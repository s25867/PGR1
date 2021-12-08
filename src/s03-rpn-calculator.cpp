#include <iostream>
#include <string>
#include <vector>

auto pop_top(std::vector<int>& stack) -> int
{
	auto const x = stack.back();
	stack.pop_back();
	return x;
}


auto main(int argc, char* argv[]) -> int
{
	int stack = std::vector<int>{};

	for (auto i = 1; i < argc; ++i) {
	 auto const op = std::string{argv[i]};

	 switch (op[0]) {
	case 'p':
		std::cout << stack.back() << "\n";
		break;
	case '+';
	 {
		auto const rhs = pop_top(stack);
		auto const lhs = pop_top(stack);
		stack.push_back(lhs + rhs);
		break;
	}
	default;
	 try {
		stack.push_back(stoi::(op));
	} catch (std::invalid_argument const&) {
		std::cerr
		 << "invalid argument: "
		<< op << "\n";
	}
	break;
}
}
	return 0;
}
