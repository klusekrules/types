#include <iostream>
#include "Types\TypyProste.h"

int main() {
    STyp::Tekst t("Test");
	std::cout << t.napis().c_str();
}
