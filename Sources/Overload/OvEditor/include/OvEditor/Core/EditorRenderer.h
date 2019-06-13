/**
* @project: Overload
* @author: Overload Tech.
* @restrictions: This software may not be resold, redistributed or otherwise conveyed to a third party.
*/

#pragma once

#include <OvRendering/LowRenderer/Camera.h>

#include <OvCore/ECS/Actor.h>
#include <OvCore/SceneSystem/SceneManager.h>
#include <OvCore/ECS/Components/CModelRenderer.h>
#include <OvCore/Resources/Material.h>
#include <OvCore/ECS/Components/CAmbientBoxLight.h>
#include <OvCore/ECS/Components/CAmbientSphereLight.h>

#include "OvEditor/Core/Context.h"

namespace OvEditor::Panels { class AView; }

namespace OvEditor::Core
{
	/**
	* Handle the rendering of the editor
	*/
	class EditorRenderer
	{
	public:
		/**
		* Create the EditorRenderer
		* @param p_context
		*/
		EditorRenderer(Context& p_context);

		/**
		* Initialize custom materials
		*/
		void InitMaterials();

		/**
		* Render the scene
		* @param p_cameraPosition
		*/
		void RenderScene(const OvMaths::FVector3& p_cameraPosition);

		/**
		* Render the User Interface
		*/
		void RenderUI();

		/**
		* Render every scene cameras
		*/
		void RenderCameras();

		/**
		* Render a guizmo at position
		* @param p_position
		* @param p_rotation
		*/
		void RenderGuizmo(const OvMaths::FVector3& p_position, const OvMaths::FQuaternion& p_rotation);

		/**
		* Render a model to the stencil buffer
		*/
		void RenderModelToStencil(const OvMaths::FMatrix4& p_worldMatrix, OvRendering::Resources::Model& p_model);

		/**
		* Render a model outline using the data stored in the stencil buffer
		*/
		void RenderModelOutline(const OvMaths::FMatrix4& p_worldMatrix, OvRendering::Resources::Model& p_model);

		/**
		* Render the actor as a selected actor (Outline)
		* @param p_actor
		* @param p_toStencil
		*/
		void RenderActorAsSelected(OvCore::ECS::Actor& p_actor, bool p_toStencil);

		/**
		* Render an actor collider
		*/
		void RenderActorCollider(OvCore::ECS::Actor& p_actor);

		/**
		* Render ambient box volume
		*/
		void RenderAmbientBoxVolume(OvCore::ECS::Components::CAmbientBoxLight& p_ambientBoxLight);

		/**
		* Render ambient sphere volume
		*/
		void RenderAmbientSphereVolume(OvCore::ECS::Components::CAmbientSphereLight& p_ambientSphereLight);

		/**
		* Render model
		*/
		void RenderModelAsset(OvRendering::Resources::Model& p_model);

		/**
		* Render texture
		*/
		void RenderTextureAsset(OvRendering::Resources::Texture& p_texture);

		/**
		* Render material
		*/
		void RenderMaterialAsset(OvCore::Resources::Material& p_material);

		/**
		* Render the grid
		*/
		void RenderGrid(const OvMaths::FVector3& p_viewPos, const OvMaths::FVector3& p_color);

		/**
		* Update the light SSBO with the current scene
		* @param p_scene
		*/
		void UpdateLights(OvCore::SceneSystem::Scene& p_scene);

	private:
		Context& m_context;

		OvCore::Resources::Material m_gridMaterial;
		OvCore::Resources::Material m_stencilFillMaterial;
		OvCore::Resources::Material m_textureMaterial;
		OvCore::Resources::Material m_outlineMaterial;
		OvCore::Resources::Material m_emptyMaterial;
		OvCore::Resources::Material m_defaultMaterial;
		OvCore::Resources::Material m_cameraMaterial;
		OvCore::Resources::Material m_guizmoArrowMaterial;
		OvCore::Resources::Material m_guizmoBallMaterial;
	};
}