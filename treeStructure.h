// tree data structure

struct qnode {
  int level;
  int flag;
  double xy[2];
  struct qnode *child[4];
};
typedef struct qnode Node;
