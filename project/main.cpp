#include <iostream>
#include <list>

using namespace std;

class Graf {
  int kenarno;
  list<int>* liste;
  bool* arama;

   public:
  Graf(int dugum);
  void dugumekle(int ilk, int son);
  void BFS(int root);
};


Graf::Graf(int dugum) {
  kenarno = dugum;
  liste = new list<int>[dugum];
}


void Graf::dugumekle(int ilk, int son) {
  liste[ilk].push_back(son);
  liste[son].push_back(ilk);
}


void Graf::BFS(int root) {
  arama = new bool[kenarno];
  for (int i = 0; i < kenarno; i++)
    arama[i] = false;

  list<int> kuyruk;

  arama[root] = true;
  kuyruk.push_back(root);

  list<int>::iterator i;

  while (!kuyruk.empty()) {
    int mkose = kuyruk.front();
    cout << "  " << mkose << "";
    kuyruk.pop_front();

    for (i = liste[mkose].begin(); i != liste[mkose].end(); i++) {
      int ykose = *i;
      if (!arama[ykose]) {
        arama[ykose] = true;
        kuyruk.push_back(ykose);
      }
    }
  }
}

int main() {
  Graf g(14);
  g.dugumekle(1 ,5);
  g.dugumekle(1, 3);
  g.dugumekle(1, 8);
  g.dugumekle(5, 2);
  g.dugumekle(5, 0);
  g.dugumekle(8, 7);
  g.dugumekle(8, 11);
  g.dugumekle(2, 9);
  g.dugumekle(2, 6);
  g.dugumekle(0, 12);
  g.dugumekle(0, 13);
  g.dugumekle(7, 4);
  g.dugumekle(7, 10);
 
  g.BFS(5);

  return 0;
}
