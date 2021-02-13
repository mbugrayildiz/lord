#include "lc.hh"

DesugarVisitor::DesugarVisitor(Module& m)
	: Visitor(m)
{
}

void DesugarVisitor::visit_FN(Node& n)
{
	// return type
	if (n[0].token == T_SYM) {
		auto t = Node(n[0].range, T_COLN);
		t.push(n[0]);
		t.push(Node(n[0].range, T_NONE));
		n[0] = t;
	}

	// argument types
	for (auto& a : n[1]) {
		if (a.token != T_SYM)
			return;

		auto t = Node(n[0].range, T_COLN);
		t.push(a);
		t.push(Node(n[0].range, T_NONE));
		a = t;
	}

	// visit body
	visit(n[2]);
}

void DesugarVisitor::visit_EQ(Node& n)
{
	if (n[0].token != T_SYM)
		return;

	auto t = Node(n[0].range, T_COLN);
	t.push(n[0]);
	t.push(Node(n[0].range, T_NONE));
	n[0] = t;
}

void DesugarVisitor::visit_PIPE(Node& n)
{
	auto right = n.pop();
	auto left = n.pop();
	right[1].push(left);
	n = right;
}
