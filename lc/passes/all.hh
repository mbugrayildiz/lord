/* NOTE:
 * The order of functions defined here is also
 * how they are meant to be applied to the AST
 * the function below does this for you
 */

void pipe_all_passes(Module& m);

void DesugarVisitor(Module& m, Node& n);
void FnVisitor(Module& m, Node& n);
Node *InferVisitor(Module& m, Node& n, Fn *f = NULL);
void RegAllocVisitor(Module& m, Node& n);
void GenVisitor(Module& m, Node& n);
