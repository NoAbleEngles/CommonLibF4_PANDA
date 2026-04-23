#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/TESCondition.h"
#include "RE/Bethesda/TESForms.h"
#include "REL/Relocation.h"

namespace RE
{
	class TESFile;
	class TESForm;
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;
	namespace BSStreamer
	{
		class ScrapStreamer;
	}

	namespace BGSCharacterTint
	{
		enum class EntrySlot
		{
			kForeheadMask,
			kEyesMask,
			kNoseMask,
			kEarsMask,
			kCheeksMask,
			kMouthMask,
			kNeckMask,
			kLipColor,
			kCheekColor,
			kEyeliner,
			kEyeSocketUpper,
			kEyeSocketLower,
			kSkinTone,
			kPaint,
			kLaughLines,
			kCheekColorLower,
			kNose,
			kChin,
			kNeck,
			kForehead,
			kDirt,
			kScars,
			kFaceDetail,
			kBrow,
			kWrinkles,
			kBeard
		};

		enum class BlendingOp : uint32_t
		{
			kBlendOpDefault,
			kBlendOpMultiply,
			kBlendOpOverlay,
			kBlendOpSoftLight,
			kBlendOpHardLight,
		};

		enum ChargenFlag : int32_t
		{
			kFlagOnOff = (1 << 0),
			kFlagChargenDetail = (1 << 1),
			kFlagTakesSkinTone = (1 << 2)
		};

		namespace Template
		{
			class __declspec(novtable) Entry
			{
			public:
				static constexpr auto RTTI{ RTTI::BGSCharacterTint__Template__Entry };
				static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__Template__Entry };

				virtual ~Entry() {};							  // 00
				virtual float GetDefaultValue() { return 0.0F; }  // 01
				virtual void InitItem(TESForm* a_owner) {};       // 02
				virtual void CopyData(Entry* a_copy) {};          // 03
				virtual void LoadImpl(TESFile* a_file) = 0;       // 04

				BGSLocalizedString name;                         // 08
				TESCondition chargenConditions;                  // 10
				stl::enumeration<EntrySlot, std::int32_t> slot;  // 18
				const std::uint16_t uniqueID{ 0 };               // 1C
				std::int8_t flags;                               // 1E
			};
			static_assert(sizeof(Entry) == 0x20);

			class Group
			{
			public:
				BGSLocalizedString name;     // 00
				std::uint32_t id;            // 08
				std::uint32_t chargenIndex;  // 0C
				BSTArray<Entry*> entries;    // 10
			};
			static_assert(sizeof(Group) == 0x28);

			class Groups
			{
			public:
				BSTArray<Group*> groups;  // 00

				Groups();
				~Groups();

				Group* AddGroup(const char* a_name);
				Entry* GetFirstEntryForSlot(EntrySlot a_slot);

				template<class Func>
				inline void ForEachEntry(Func&& a_func)
				{
					// Iterate through all groups and their entries
					for (auto* group : groups) {
						if (group && group->entries.data()) {
							for (auto* entry : group->entries) {
								if (entry) {
									a_func(entry);
								}
							}
						}
					}
				}
			};
			static_assert(sizeof(Groups) == 0x18);

			class Mask : public Entry
			{
				static constexpr auto RTTI{ RTTI::BGSCharacterTint__Template__Mask };
				static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__Template__Mask };
			public:
				virtual ~Mask() {};                               // 00
				virtual float GetDefaultValue() { return 0.0F; }  // 01
				virtual void InitItem(TESForm* a_owner) {};       // 02
				virtual void CopyData(Entry* a_copy) {};          // 03
				virtual void LoadImpl(TESFile* a_file) {};        // 04

				BSFixedString texture;  // 20
				BlendingOp blendOp;     // 28
				uint32_t unk2C;			// 2C

				static Mask* Create();
			};
			static_assert(sizeof(Mask) == 0x30);

			class Palette : public Entry
			{
				static constexpr auto RTTI{ RTTI::BGSCharacterTint__Template__Palette };
				static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__Template__Palette };
			public:
				virtual ~Palette() {};                            // 00
				virtual float GetDefaultValue() { return 0.0F; }  // 01
				virtual void InitItem(TESForm* a_owner) {};       // 02
				virtual void CopyData(Entry* a_copy) {};          // 03
				virtual void LoadImpl(TESFile* a_file) {};        // 04

				struct ColorData
				{
					BGSColorForm* colorForm;  // 00
					float alpha;              // 08
					BlendingOp blendOp;       // 0C
					uint16_t colorID;         // 10
					uint16_t unk12;           // 12
					uint32_t unk14;           // 14
				};

				BSFixedString texture;     // 20
				uint32_t unk28;            // 28
				uint32_t unk2C;            // 2C
				BSTArray<ColorData> colors;  // 30

				inline ColorData* GetColorDataByID(uint16_t colorID)
				{
					for (uint32_t i = 0; i < colors.size(); i++) {
						if (colors[i].colorID == colorID) {
							return &colors[i];
						}
					}

					return nullptr;
				}
			};
			static_assert(sizeof(Palette) == 0x48);

			class TextureSet : public Entry 
			{
				static constexpr auto RTTI{ RTTI::BGSCharacterTint__Template__TextureSet };
				static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__Template__TextureSet };

			public:
				virtual ~TextureSet() {};						  // 00
				virtual float GetDefaultValue() { return 0.0F; }  // 01
				virtual void InitItem(TESForm* a_owner) {};       // 02
				virtual void CopyData(Entry* a_copy) {};          // 03
				virtual void LoadImpl(TESFile* a_file) {};        // 04

				BSFixedString diffuse;   // 20
				BSFixedString normal;    // 28
				BSFixedString specular;  // 30
				BlendingOp blendOp;      // 38
				float defaultValue;      // 3C

				//static TextureSet* Create() {};
			};
			static_assert(sizeof(TextureSet) == 0x40);
		}

		class Entry
		{
			static constexpr auto RTTI{ RTTI::BGSCharacterTint__Entry };
			static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__Entry };
		public:
			virtual ~Entry() {};                                                            // 00
			virtual bool GetIsIdentical(Entry* rhs) { return false; };                     // 01 
			virtual void CopyData(Entry* rhs) {};                                          // 02
			virtual void SetFromTemplateDefault(Template::Entry* tmpl) {};                 // 03
			virtual bool GetMatchesTemplateDefault(Template::Entry* tmpl) { return false; }; // 04
			virtual uint32_t GetType(void) = 0;                                            // 05
			virtual void Unk_06(void) {};                                                  // 06

			enum
			{
				kTypeMask = 0,
				kTypePalette,
				kTypeTexture
			};

			inline std::string GetTypeString()
			{
				switch (GetType()) {
				case kTypeMask:
					return "Mask";
				case kTypePalette:
					return "Palette";
				case kTypeTexture:
					return "TextureSet";
				default:
					return "Unknown";
				}
			}

			Template::Entry* templateEntry;  // 08
			uint16_t tintIndex;              // 10
			uint8_t percent;                // 12	divided by 100
			uint8_t pad13;                  // 13
			uint32_t pad14;                 // 14
		};
		static_assert(sizeof(Entry) == 0x18);

		class MaskEntry : public Entry
		{
			static constexpr auto RTTI{ RTTI::BGSCharacterTint__MaskEntry };
			static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__MaskEntry };
		public:
			virtual ~MaskEntry() {};
			virtual void SetFromTemplateDefault(Template::Entry* tmpl) override {};     // 03
			virtual bool GetMatchesTemplateDefault(Template::Entry* tmpl) override { return false; }; // 04
			virtual uint32_t GetType(void) override { return kTypeMask; };  // 05
			virtual void Unk_06(void) override {};                          // 06
		};
		static_assert(sizeof(MaskEntry) == 0x18);

		class PaletteEntry : public Entry
		{
			static constexpr auto RTTI{ RTTI::BGSCharacterTint__PaletteEntry };
			static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__PaletteEntry };
		public:
			virtual ~PaletteEntry() {};

			virtual bool GetIsIdentical(Entry* rhs) { return false; };                                 // 01
			virtual void CopyData(Entry* rhs) {};                                                      // 02
			virtual void SetFromTemplateDefault(Template::Entry* tmpl) override {};                    // 03
			virtual bool GetMatchesTemplateDefault(Template::Entry* tmpl) override { return false; };  // 04
			virtual uint32_t GetType(void) override { return kTypePalette; };                          // 05
			virtual void Unk_06(void) override {};       // 06

			union Color
			{
				struct Channel
				{
					uint8_t red;
					uint8_t green;
					uint8_t blue;
					uint8_t unused;
				} channel;  // 18
				uint32_t bgra;
			} color;

			int16_t colorID;  // 1C - ID of the color from the template's list
			uint16_t pad1E;   // 1E
		};
		static_assert(sizeof(PaletteEntry) == 0x20);

		class TextureSetEntry : public Entry
		{
			static constexpr auto RTTI{ RTTI::BGSCharacterTint__TextureSetEntry };
			static constexpr auto VTABLE{ VTABLE::BGSCharacterTint__TextureSetEntry };
		public:
			virtual ~TextureSetEntry() {};																// 00
			virtual void SetFromTemplateDefault(Template::Entry* tmpl) override {};						// 03
			virtual bool GetMatchesTemplateDefault(Template::Entry* tmpl) override { return false; };	// 04
			virtual uint32_t GetType(void) override { return kTypeTexture; };							// 05
			virtual void Unk_06(void) override {};														// 06
		};
		static_assert(sizeof(TextureSetEntry) == 0x18);

		class Entries
		{
		public:
			// Iterator types
			using value_type = Entry*;
			using pointer = Entry**;
			using const_pointer = Entry* const*;
			using reference = Entry*&;
			using const_reference = Entry* const&;
			using size_type = std::uint32_t;
			using difference_type = std::ptrdiff_t;
			using iterator = Entry**;
			using const_iterator = Entry* const*;

			Entry** data{ nullptr };      // 00
			std::uint32_t capacity{ 0 };  // 08
			std::uint32_t pad0C{ 0 };     // 0C
			std::uint32_t size{ 0 };      // 10

			Entries();
			explicit Entries(std::uint32_t a_reserve);
			~Entries();

			// Iterator methods
			iterator begin() noexcept { return data; }
			const_iterator begin() const noexcept { return data; }
			const_iterator cbegin() const noexcept { return data; }
			
			iterator end() noexcept { return data + size; }
			const_iterator end() const noexcept { return data + size; }
			const_iterator cend() const noexcept { return data + size; }

			// Container methods
			bool empty() const noexcept { return size == 0; }
			size_type get_size() const noexcept { return size; }
			
			// Element access
			reference at(size_type pos) { 
				if (pos >= size) throw std::out_of_range("Index out of range");
				return data[pos]; 
			}
			const_reference at(size_type pos) const { 
				if (pos >= size) throw std::out_of_range("Index out of range");
				return data[pos]; 
			}
			
			reference operator[](size_type pos) noexcept { return data[pos]; }
			const_reference operator[](size_type pos) const noexcept { return data[pos]; }
			
			reference front() noexcept { return data[0]; }
			const_reference front() const noexcept { return data[0]; }
			
			reference back() noexcept { return data[size - 1]; }
			const_reference back() const noexcept { return data[size - 1]; }

			void Clear();
			void RemoveAt(std::uint32_t a_index);
			void CopyFrom(Entries& a_rhs);
			void Add(Entry* a_entry, Template::Groups* a_groups);
			Entry* GetEntryByID(std::uint16_t a_id);
			Entry* GetFirstEntryForSlot(Template::Groups* a_groups, EntrySlot a_slot);
			void MakeContiguous(Template::Groups* a_groups);
			void MakeMinimal(Template::Groups* a_groups);
			void SetEntryData(Template::Groups& a_groups, std::uint16_t a_id, float a_value, std::uint32_t a_flags);
			void Sort(Template::Groups* a_groups);
			void LoadGame(Template::Groups* a_groups, BGSLoadFormBuffer* a_buf, std::uint32_t a_arg);
			void SaveGame(Template::Groups& a_groups, BGSSaveFormBuffer& a_buf);
			void SaveToBuffer(Template::Groups& a_groups, BSStreamer::ScrapStreamer& a_stream);
			void LoadFromBuffer(Template::Groups* a_groups, BSStreamer::ScrapStreamer& a_stream, std::uint32_t a_flags);
		};
	}
}
