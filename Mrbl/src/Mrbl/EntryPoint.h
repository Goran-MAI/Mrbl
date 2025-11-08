#pragma once

#ifdef MRBL_PLATFORM_WINDOWS

extern Mrbl::Application* Mrbl::CreateApplication(); // Deklaration, Implementation kommt aus SandboxApp

int main(int argc, char** argv) { // Universeller Einstiegspunkt für jede mögliche App, die Mrbl::Application erbt.
	
	auto app = Mrbl::CreateApplication(); // Hier wird die Anwendung erzeugt - "Factory"-Methode
	app->Run();
	delete app;

	return 0;
}

#endif
