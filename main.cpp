#include "String.h"

int main()
{
	String sir, s;

	std::cout << "Lungimea stringului este: " << sir.getLength() << '\n';

	std::cin >> sir;

	sir.pushBack('a');
	sir.pushBack('x');

	std::cout << sir << '\n';

	s = sir;

	if (sir.findChar('a'))
		std::cout << "Primul string contine acest caracter! \n";

	else std::cout << "Primul string nu contine acest caracter! \n";

	sir.popBack();

	std::cout << sir << '\n';

	if (s.findString(sir))
		std::cout << "Primul string se regaseste in cel de al doilea sir! \n";

	else std::cout << "Primul string se nu regaseste in cel de al doilea sir! \n";

	String str("Ana are mere!");

	std::cout << "Caracterul 'e' se gaseste in str de: " << str.countChar('e') << " ori\n";

	s.swap(str);

	std::cout << str << '\n';

	if (!str.empty())
		std::cout << "Stringul str nu este gol! \n";

	else std::cout << "Stringul str este gol! \n";

	std::cout << sir << '\n';

	if (s.compare(sir) == 0)
		std::cout << "Stringul s este identic cu stringul sir! \n";

	else std::cout << "Sirurile sunt diferite! \n";

	std::cout << "cacat \n";

	return 0;
}