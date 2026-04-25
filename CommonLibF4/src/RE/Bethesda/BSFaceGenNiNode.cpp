#include "F4SE/Impl/PCH.h"
#include "RE/Bethesda/BSFaceGenNiNode.h"

namespace RE
{
	BSFaceGenNiNode::BSFaceGenNiNode() :
		NiNode(0),
		headPartTransform{},
		animationData(nullptr),
		lastUpdateTime(-1.0f),
		flags(0x0C),
		partFlags(0),
		pad1DF(0),
		resourceHandle(nullptr),
		pad1E8(0)
	{
		stl::emplace_vtable(this);
		
		// Initialize the head part transforms to identity (from the asm analysis)
		// These appear to be initialized from static data in the original code
		for (auto& transform : headPartTransform) {
			transform.MakeIdentity();
		}
	}

	BSFaceGenNiNode::~BSFaceGenNiNode()
	{
		// Clear morphing data from children
		ClearMorphingDataFromChildren();

		// Release resource handle if it exists (based on asm analysis)
		if (resourceHandle) {
			// The asm shows complex resource release logic here
			// This would need to interface with BSResource system
			resourceHandle = nullptr;
		}

		// Release animation data if it exists
		// In a real implementation, this would need proper reference counting
		if (animationData) {
			// TODO: Proper cleanup when BSFaceGenAnimationData is fully defined
			animationData = nullptr;
		}
	}

	NiObject* BSFaceGenNiNode::CreateClone(NiCloningProcess& a_cloning)
	{
		auto* clone = new BSFaceGenNiNode();
		clone->CopyMembers(this, a_cloning);
		return clone;
	}

	void BSFaceGenNiNode::CopyMembers(BSFaceGenNiNode* a_src, NiCloningProcess& a_cloning)
	{
		// Copy base class members (NiNode doesn't have CopyMembers in the interface we have)
		// We would need to copy the relevant NiNode members manually here

		// Copy head part transforms
		for (std::uint32_t i = 0; i < 3; ++i) {
			headPartTransform[i] = a_src->headPartTransform[i];
		}

		// Copy other members
		animationData = a_src->animationData;  // Raw pointer copy - would need ref counting in real impl
		lastUpdateTime = a_src->lastUpdateTime;
		flags = a_src->flags;
		partFlags = a_src->partFlags;
		// resourceHandle is not copied (each instance needs its own)
	}

	void BSFaceGenNiNode::UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_flags)
	{
		// Check if morphing update is needed
		if (!(flags & 1)) {  // If bit 0 is not set
			UpdateMorphing(a_data);
		}

		// Call parent implementation
		NiNode::UpdateDownwardPass(a_data, a_flags);
	}

	void BSFaceGenNiNode::SetAnimationData(BSFaceGenAnimationData* a_animData)
	{
		// Based on the asm, this uses atomic reference counting
		// For now, simple assignment - would need proper ref counting in real implementation
		if (animationData != a_animData) {
			// TODO: Release old data and add ref to new data when fully defined
			animationData = a_animData;
		}
	}

	void BSFaceGenNiNode::FixSkinInstances(NiNode* a_node, BSTriShape* a_triShape, bool a_flag)
	{
		// The asm shows this creates a temporary scrap hash map and calls the other overload
		// This is a complex function involving memory allocation and iteration over children
		// Based on asm analysis, it appears to fix skin instances for facial geometry
		if (!a_triShape) {
			return;
		}

		// The actual implementation would create a BSTScrapHashMap and call the other overload
		// For now, we'll implement a simplified version
	}

	void BSFaceGenNiNode::FixSkinInstances(NiNode* a_node, BSTriShape* a_triShape, 
										  BSTScrapHashMap<BSFixedString, NiAVObject*>& a_map, bool a_flag)
	{
		// Based on asm analysis, this method:
		// 1. Gets extra data from the triShape
		// 2. Processes skin instances
		// 3. Updates the head part reference
		if (!a_triShape) {
			return;
		}

		// The asm shows complex logic for handling skin instances
		// This would need to interact with the triShape's extra data
	}

	void BSFaceGenNiNode::UpdateAllChildrenMorphData(bool a_forceUpdate)
	{
		// Based on asm analysis, this iterates through all children
		// and updates their morph data if they are BSTriShape objects
		for (std::uint16_t i = 0; i < children.size(); ++i) {
			auto* child = children[i].get();
			if (!child) {
				continue;
			}

			// The asm shows this checks if the child is a BSTriShape
			// and has facial morph data, then updates it
			// This is a complex function involving distance calculations
			// and morph application
		}

		// Clear certain flags after update
		if (partFlags & 1) {
			flags &= 0xFEFF;  // Clear bit 8
		}
	}

	void BSFaceGenNiNode::ApplyFacialMorphs(FaceGenUpdateData& a_updateData)
	{
		// Based on asm analysis, this function:
		// 1. Collects morph indices and weights from animation data
		// 2. Applies them to the morph data head
		if (!animationData || !a_updateData.morphDataHead) {
			return;
		}

		// The asm shows complex morph collection and application logic
		// This would interface with BSFaceGenMorphDataHead::ApplyMorphs
	}

	bool BSFaceGenNiNode::QMorphLoaded(std::uint8_t a_morphIndex)
	{
		// Based on asm analysis, this checks if a specific morph is loaded
		// by iterating through children and checking their morph data
		for (std::uint16_t i = 0; i < children.size(); ++i) {
			auto* child = children[i].get();
			if (!child) {
				continue;
			}

			// The asm shows this checks BSTriShape children for morph existence
			// If found, returns true
		}
		return false;
	}

	void BSFaceGenNiNode::ResetFaceBaseMorphData()
	{
		// Based on asm analysis, this iterates through children
		// and resets their base morph data
		for (std::uint16_t i = 0; i < children.size(); ++i) {
			auto* child = children[i].get();
			if (!child) {
				continue;
			}

			// The asm shows this checks for BSTriShape children
			// and calls ResetAllBaseVertices on their extra data
		}
	}

	void BSFaceGenNiNode::ClearMorphingDataFromChildren()
	{
		// Based on asm analysis, this appears to clear morphing data
		// from child geometry objects
		// The actual implementation would traverse children and clear their morph data
	}

	void BSFaceGenNiNode::UpdateMorphing(NiUpdateData& a_data)
	{
		// Based on asm analysis, this is a complex function that:
		// 1. Checks if animation data exists and needs updating
		// 2. Updates animation data with delta time
		// 3. Checks visibility and distance requirements
		// 4. Calls UpdateAllChildrenMorphData if needed

		if (flags & 1) {  // If disabled flag is set
			return;
		}

		if (!animationData) {
			return;
		}

		// Store current update time from a_data (we can't access time directly without full definition)
		// lastUpdateTime = a_data.time;

		// The asm shows complex logic for checking update conditions
		// including distance calculations and visibility checks

		// Update animation data
		if (flags & 4) {  // If update flag is set
			// Reset update flags and update animation
			// Note: animationData = nullptr is simplified - actual logic is more complex
			flags &= 0xFFFE;  // Clear bit 0
		}

		// Check if morphing update is needed
		bool needsUpdate = false;
		if (animationData) {
			// The asm shows checking animation data state
			needsUpdate = true;  // Simplified logic
		}

		if (needsUpdate || (partFlags & 1)) {
			// Find visible child node
			NiAVObject* visibleChild = nullptr;
			for (std::uint16_t i = 0; i < children.size(); ++i) {
				auto* child = children[i].get();
				if (child) {
					visibleChild = child;
					break;
				}
			}

			if (visibleChild && 
				(partFlags & 1) ||
				(!(flags & 0x1820))) {  // Complex flag checking from asm
				
				UpdateAllChildrenMorphData(needsUpdate);
			}
		}
	}
}

