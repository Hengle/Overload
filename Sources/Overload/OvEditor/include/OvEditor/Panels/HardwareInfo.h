/**
* @project: Overload
* @author: Overload Tech.
* @restrictions: This software may not be resold, redistributed or otherwise conveyed to a third party.
*/

#pragma once

#include <OvUI/Panels/PanelWindow.h>
#include <OvUI/Widgets/Plots/PlotLines.h>
#include <OvUI/Widgets/Plots/PlotHistogram.h>

namespace OvAnalytics::Hardware { class HardwareInfo; }

namespace OvEditor::Panels
{
	class HardwareInfo : public OvUI::Panels::PanelWindow
	{
	public:
		/**
		* Defines some display modes for the hardware info information
		*/
		enum class EDisplayMode
		{
			PLOT_LINES,
			PLOT_HISTOGRAM
		};

		/**
		* Constructor
		* @param p_title
		* @param p_opened
		* @param p_windowSettings
		* @param p_logFrequency
		* @param p_maxElements
		* @param p_displayMode
		*/
		HardwareInfo
		(
			const std::string& p_title,
			bool p_opened,
			const OvUI::Settings::PanelWindowSettings& p_windowSettings,
			float p_logFrequency,
			size_t p_maxElements,
			EDisplayMode p_displayMode
		);

		/**
		* Destructor
		*/
		~HardwareInfo();

		/**
		* Update hardware info
		* @param p_deltaTime
		*/
		void Update(float p_deltaTime);

	private:
		float p_updateTimer = 0.f;
		float m_logFrequency;
		size_t m_maxElements;
		OvUI::Widgets::Plots::APlot* m_cpuUsage;
		OvUI::Widgets::Plots::APlot* m_gpuUsage;
		OvUI::Widgets::Plots::APlot* m_ramUsage;
		OvAnalytics::Hardware::HardwareInfo* m_hardwareInfo;
	};
}