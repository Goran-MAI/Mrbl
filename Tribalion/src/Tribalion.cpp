#include <Mrbl.h>

class Tribalion : public Mrbl::Application {
public:
	Tribalion() {

	}

	~Tribalion()
	{

	}
};


Mrbl::Application* Mrbl::CreateApplication() {
	return new Tribalion(); // Tribalion erbt von Mrbl::Application
}