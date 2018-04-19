#ifndef MYCUTCALLBACK_H_
#define MYCUTCALLBACK_H_

#include <ilcplex/ilocplex.h>
#include "Graph.h"
extern "C"{
#include "concorde.h"
}

class MyCutCallback : public IloCplex::UserCutCallbackI {
public:
	MyCutCallback(IloEnv env, IloArray< IloArray <IloBoolVarArray> >& x, IloBoolVarArray& Fs, IloBoolVarArray& Ft, Graph& graph);

	//metodo que retorna uma copia do calback. Cplex exige este método.
	IloCplex::CallbackI* duplicateCallback() const;

	// codigo executado pelo Cplex
	void main();

private:
	IloArray< IloArray <IloBoolVarArray> >& x;
	IloBoolVarArray& Fs;
	IloBoolVarArray& Ft;

	Graph& graph;

	void verifyComponent(vector<int> &component, int f);

	void addTspConcordeCuts(CCtsp_lpcut_in **tsp_cuts, vector<int> &component, unsigned int f);

	void getComponents(vector<vector<int> >& components, vector<vector<int> >& adjList);

	void dfs(int v, vector<int> &component, vector<vector<int>>& adjList, vector<int>& visited);
};

#endif /* MYCUTCALLBACK_H_ */
