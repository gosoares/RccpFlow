#ifndef MYLAZYCALLBACK_H_
#define MYLAZYCALLBACK_H_

#include <ilcplex/ilocplex.h>
#include "Graph.h"

class MyLazyCallback : public IloCplex::LazyConstraintCallbackI {
public:
	MyLazyCallback(IloEnv env, IloArray< IloArray <IloBoolVarArray> >& x, Graph& graph);

	//metodo que retorna uma copia do calback. Cplex exige este método.
	IloCplex::CallbackI* duplicateCallback() const;

	// codigo executado pelo Cplex
	void main();

private:
	IloArray< IloArray <IloBoolVarArray> >& x;
	Graph& graph;

	void getComponents(vector<vector<int> >& components, vector<vector<int> >& adjList);

	void dfs(int v, vector<int> &component, vector<vector<int>>& adjList, vector<int>& visited);
};


#endif /* MYLAZYCALLBACK_H_ */
