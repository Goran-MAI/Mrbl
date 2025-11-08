#include <Mrbl.h>

class Sandbox : public Mrbl::Application {
public:
	Sandbox() {

	}

	~Sandbox() 
	{

	}
};


Mrbl::Application* Mrbl::CreateApplication() {
	return new Sandbox(); // Sandbox erbt von Mrbl::Application
}