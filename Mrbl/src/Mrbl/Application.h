#pragma once
#include "Core.h"

namespace Mrbl {

	class MRBL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in Client
	Application* CreateApplication();
}

