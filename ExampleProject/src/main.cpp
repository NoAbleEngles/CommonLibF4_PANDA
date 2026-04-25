// Define F4_SUPPORT_NG to build for Next-Gen (1.11+) version
// Leave undefined for Original Game (1.10.163 and below)
// #define F4_SUPPORT_NG

namespace
{
	void InitializeLogging()
	{
#ifndef NDEBUG
		auto sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
#else
		auto path = logger::log_directory();
		if (!path) {
			return;
		}

		*path /= fmt::format(FMT_STRING("{}.log"), Version::PROJECT);
		auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);
#endif

		auto log = std::make_shared<spdlog::logger>("global log"s, std::move(sink));

#ifndef NDEBUG
		log->set_level(spdlog::level::trace);
#else
		log->set_level(spdlog::level::info);
		log->flush_on(spdlog::level::warn);
#endif

		spdlog::set_default_logger(std::move(log));
		spdlog::set_pattern("%g(%#): [%^%l%$] %v"s);

		logger::info("{} v{}", Version::PROJECT, Version::NAME);
	}

	bool CheckVersion(const F4SE::QueryInterface* a_f4se)
	{
		if (a_f4se->IsEditor()) {
			logger::critical("loaded in editor");
			return false;
		}

		const auto ver = a_f4se->RuntimeVersion();

#ifdef F4_SUPPORT_NG
		// Next-Gen version check (1.11.191+)
		if (ver < F4SE::RUNTIME_1_11_191) {
			logger::critical("unsupported runtime v{}, requires 1.11.191+", ver.string());
			return false;
		}
		logger::info("detected Next-Gen runtime v{}", ver.string());
#else
		// Original Game version check (1.10.163 and below)
		if (ver < F4SE::RUNTIME_1_10_162) {
			logger::critical("unsupported runtime v{}, requires 1.10.162+", ver.string());
			return false;
		}
		if (ver > F4SE::RUNTIME_1_10_163) {
			logger::critical("unsupported runtime v{}, this plugin is for OG version (max 1.10.163)", ver.string());
			return false;
		}
		logger::info("detected Original Game runtime v{}", ver.string());
#endif

		return true;
	}
}

extern "C" DLLEXPORT bool F4SEAPI F4SEPlugin_Query(const F4SE::QueryInterface* a_f4se, F4SE::PluginInfo* a_info)
{
	InitializeLogging();

	a_info->infoVersion = F4SE::PluginInfo::kVersion;
	a_info->name = Version::PROJECT.data();
	a_info->version = Version::MAJOR;

	return CheckVersion(a_f4se);
}

extern "C" DLLEXPORT bool F4SEAPI F4SEPlugin_Load(const F4SE::LoadInterface* a_f4se)
{
	F4SE::Init(a_f4se);

	logger::info("hello world!");

	return true;
}
