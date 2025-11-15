#include "mrblpch.h"
#include "Application.h"

#include "Mrbl/Events/ApplicationEvent.h"
#include "Mrbl/Log.h"

namespace Mrbl {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);

		if (e.IsInCategory(EventCategoryApplication)) {
			MRBL_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			MRBL_TRACE(e);
		}


		while (true) {
			// endless loop
		}
	}
}
