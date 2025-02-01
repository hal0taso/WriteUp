#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// random_device get_rand_dev;
int N_STORE = 0;
int SEED = 0;
mt19937_64 get_rand_mt(SEED);
int WIDTH = 100;

typedef struct P
{
  int x, y, value;

  bool operator<(const struct P &other) const
  {
    return value < other.value;
  }

  bool operator>(const struct P &other) const
  {
    return value > other.value;
  }

} Point;

Point rotate(Point &a, int base)
{
  Point b = {a.x + a.y + base, a.x - a.y + base, a.value};
  return b;
}

Point invert(Point &a, int base)
{
  Point b = {(a.x + a.y) / 2 - base, (a.x - a.y) / 2, a.value};
  return b;
}

void output(Point &p1, Point &p2, Point &p3, Point &p4)
{
  cout << p1.x << ' ' << p1.y << ' ' << p2.x << ' ' << p2.y << ' ' << p3.x << ' ' << p3.y << ' ' << p4.x << ' ' << p4.y << endl;
}

typedef struct Q
{
  int n1;
  int n2;
  bool n3;
  bool n4;

  Q(int _n1, int _n2, bool _n3, bool _n4) : n1(_n1), n2(_n2), n3(_n3), n4(_n4)
  {
  }

  bool operator<(const struct Q &other) const
  {
    // Your priority logic goes here
    return n1 < other.n1;
  }

  bool operator>(const struct Q &other) const
  {
    // Your priority logic goes here
    return n1 > other.n1;
  }

} quad;

void debug(vector<vector<bool>> C)
{
  // for debug
  for (int i = 0; i < C.size(); i++)
  {
    for (int j = 0; j < C[i].size(); j++)
    {
      if (C[i][j])
        cout << '#';
      else
        cout << '.';
    }
    cout << '\n';
  }
}

void debug(set<int> S)
{
  // for debug
  cout << '{';
  for (auto s : S)
  {
    cout << s << ',';
  }
  cout << '}';
  cout << '\n';
}

void debug(vector<set<int>> C)
{
  cout << 's' << 'i' << 'z' << 'e' << ':' << C.size() << endl;
  // for debug
  for (int i = 0; i < C.size(); i++)
  {
    if (C[i].size() > 0)
    {
      cout << i << ':' << '{';
      for (auto s : C[i])
      {
        cout << s << ',';
      }
      cout << '}';
      cout << '\n';
    }
  }
}

void debug(vector<bool> C)
{
  // for debug
  for (int i = 0; i < C.size(); i++)
  {
    if (C[i])
      cout << '#';
    else
      cout << '.';
  }
  cout << '\n';
}

void debug(Point p)
{
  cout << '(' << p.x << ',' << p.y << ')' << endl;
}

void debug(priority_queue<Point> que)
{
  while (!que.empty())
  {
    debug(que.top());
    cout << ',' << '\n';
    que.pop();
  }
}

void debug(priority_queue<Point, vector<Point>, greater<Point>> que)
{
  while (!que.empty())
  {
    debug(que.top());
    que.pop();
  }
}

int calc_value(int x, int y, int c)
{
  return (x - c) * (x - c) + (y - c) * (y - c) + 1;
}

bool drawable(vector<bool> &lineMarker, int s, int t)
{
  if (s > t)
  {
    swap(s, t);
  }
  for (int chk = s; chk < t; chk++)
  {
    if (lineMarker[chk])
    {
      return false;
    }
  }

  return true;
}

bool drawable(Point &p1, Point &p2, Point &p3, Point &p4,
              vector<vector<bool>> &lineMarker_p1_to_p2, vector<vector<bool>> &lineMarker_p2_to_p3)
{
  /*
  p4 <- p3
  |     ^
  v     |
  p1 -> p2
         */
  bool p1_p2 = drawable(lineMarker_p1_to_p2[p1.y], p1.x, p2.x);
  bool p2_p3 = drawable(lineMarker_p2_to_p3[p2.x], p2.y, p3.y);
  bool p3_p4 = drawable(lineMarker_p1_to_p2[p3.y], p3.x, p4.x);
  bool p4_p1 = drawable(lineMarker_p2_to_p3[p4.x], p1.y, p4.y);
  return p1_p2 && p2_p3 && p3_p4 && p4_p1;
}

void draw_line(vector<bool> &lineMarker, int s, int t)
{
  if (s > t)
  {
    swap(s, t);
  }
  for (int chk = s; chk < t; chk++)
  {
    lineMarker[chk] = true;
  }
}

void draw_line(Point &p1, Point &p2, Point &p3, Point &p4,
               vector<vector<bool>> &lineMarker_p1_to_p2, vector<vector<bool>> &lineMarker_p2_to_p3)
{
  draw_line(lineMarker_p1_to_p2[p1.y], p1.x, p2.x); // p1 -> p2
  draw_line(lineMarker_p2_to_p3[p2.x], p2.y, p3.y); // p2 -> p3
  draw_line(lineMarker_p1_to_p2[p3.y], p3.x, p4.x); // p3 -> p4
  draw_line(lineMarker_p2_to_p3[p4.x], p1.y, p4.y); // p4 -> p1
}

void append_point(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
                  vector<set<int>> &choiceRotX, vector<set<int>> &choiceRotY,
                  vector<vector<bool>> &C, vector<vector<Point>> &ans, priority_queue<Point> &que,
                  Point p1, Point p2, Point p3, Point p4, bool rot, int base)
{
  Point invp4 = invert(p4, base);
  Point rotp4 = rotate(p4, base);

  choiceX[p4.x].insert(p4.y);
  choiceY[p4.y].insert(p4.x);
  if (rot)
  {
    C[invp4.x][invp4.y] = true;
    ans.push_back({invert(p1, base), invert(p2, base), invert(p3, base), invp4});
    que.push(invp4);

    choiceRotX[invp4.x].insert(invp4.y);
    choiceRotY[invp4.y].insert(invp4.x);
  }
  else
  {
    C[p4.x][p4.y] = true;
    ans.push_back({p1, p2, p3, p4});
    que.push(p4);

    choiceRotX[rotp4.x].insert(rotp4.y);
    choiceRotY[rotp4.y].insert(rotp4.x);
  }
}

void append_point(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
                  vector<set<int>> &choiceRotX, vector<set<int>> &choiceRotY,
                  vector<vector<bool>> &C, vector<vector<Point>> &ans, priority_queue<Point, vector<Point>, greater<Point>> &que,
                  Point p1, Point p2, Point p3, Point p4, bool rot, int base)
{
  Point invp4 = invert(p4, base);
  Point rotp4 = rotate(p4, base);

  choiceX[p4.x].insert(p4.y);
  choiceY[p4.y].insert(p4.x);
  if (rot)
  {
    C[invp4.x][invp4.y] = true;
    ans.push_back({invert(p1, base), invert(p2, base), invert(p3, base), invp4});
    que.push(invp4);

    choiceRotX[invp4.x].insert(invp4.y);
    choiceRotY[invp4.y].insert(invp4.x);
  }
  else
  {
    C[p4.x][p4.y] = true;
    ans.push_back({p1, p2, p3, p4});
    que.push(p4);

    choiceRotX[rotp4.x].insert(rotp4.y);
    choiceRotY[rotp4.y].insert(rotp4.x);
  }
}

bool searchHor(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
               vector<vector<bool>> &lineHor, vector<vector<bool>> &lineVert,
               vector<vector<bool>> &C,
               Point p1, int c, int N,
               bool rot, int base, priority_queue<quad, vector<quad>, greater<quad>> &int_que, int &cnt, vector<vector<Point>> &cand)
{
  /*
   Search right (positive direction of X axis)
  */

  auto iterX = choiceY[p1.y].upper_bound(p1.x);
  if (iterX != choiceY[p1.y].end())
  {
    Point p2 = {*iterX, p1.y, calc_value(*iterX, p1.y, c)};
    // Search top (positive direction of Y axis)
    auto iterY = choiceX[p2.x].upper_bound(p2.y);
    if (iterY != choiceX[p2.x].end())
    {
      Point p3 = {p2.x, *iterY, calc_value(p2.x, *iterY, c)};
      Point p4 = {p1.x, p3.y, calc_value(p1.x, p3.y, c)};
      Point invp4 = invert(p4, base);

      // assert that there is no point on p4 -> p1
      iterY = choiceX[p1.x].upper_bound(p1.y);
      iterX = choiceY[p4.y].upper_bound(p4.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && (iterY == choiceX[p1.x].end() || *iterY > p4.y) && *iterX == p3.x && drawable(p1, p2, p3, p4, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, true, rot));
        cnt++;
      }
    }
    // Search bottom (negative direction of Y axis)
    iterY = choiceX[p2.x].lower_bound(p2.y);
    if (iterY != choiceX[p2.x].begin())
    {
      iterY--;
      Point p3 = {p2.x, *iterY, calc_value(p2.x, *iterY, c)};
      Point p4 = {p1.x, p3.y, calc_value(p1.x, p3.y, c)};
      Point invp4 = invert(p4, base);

      iterY = choiceX[p4.x].upper_bound(p4.y);
      iterX = choiceY[p4.y].upper_bound(p4.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && *iterY == p1.y && *iterX == p3.x && drawable(p1, p2, p3, p4, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, true, rot));
        cnt++;
      }
    }
  }

  /*
  Search left (negative direction of X axis)
  */

  iterX = choiceY[p1.y].lower_bound(p1.x);
  if (iterX != choiceY[p1.y].begin())
  {
    iterX--;
    Point p2 = {*iterX, p1.y, calc_value(*iterX, p1.y, c)};

    // search top (positive direction of Y axis)
    auto iterY = choiceX[p2.x].upper_bound(p2.y);
    if (iterY != choiceX[p2.x].end())
    {
      Point p3 = {p2.x, *iterY, calc_value(p2.x, *iterY, c)};
      Point p4 = {p1.x, p3.y, calc_value(p1.x, p3.y, c)};
      Point invp4 = invert(p4, base);

      iterY = choiceX[p1.x].upper_bound(p1.y);
      iterX = choiceY[p3.y].upper_bound(p3.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && (iterY == choiceX[p1.x].end() || *iterY > p4.y) && (iterX == choiceY[p3.y].end() || *iterX > p4.x) && drawable(p1, p2, p3, p4, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, true, rot));
        cnt++;
      }
    }

    // search bottom (negative direction of Y axis)
    iterY = choiceX[p2.x].lower_bound(p2.y);
    if (iterY != choiceX[p2.x].begin())
    {
      iterY--;
      Point p3 = {p2.x, *iterY, calc_value(p2.x, *iterY, c)};
      Point p4 = {p1.x, p3.y, calc_value(p1.x, p3.y, c)};
      Point invp4 = invert(p4, base);

      iterY = choiceX[p4.x].upper_bound(p4.y);
      iterX = choiceY[p3.y].upper_bound(p3.x);

      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && *iterY == p1.y && (iterX == choiceY[p3.y].end() || *iterX > p4.x) && drawable(p1, p2, p3, p4, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, true, rot));
        cnt++;
      }
    }
  }
  return false;
}

bool searchHor(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
               vector<vector<bool>> &lineHor, vector<vector<bool>> &lineVert,
               vector<vector<bool>> &C,
               Point p1, int c, int N,
               bool rot, int base, priority_queue<quad> &int_que, int &cnt, vector<vector<Point>> &cand)
{
  /*
   Search right (positive direction of X axis)
  */

  auto iterX = choiceY[p1.y].upper_bound(p1.x);
  if (iterX != choiceY[p1.y].end())
  {
    Point p2 = {*iterX, p1.y, calc_value(*iterX, p1.y, c)};
    // Search top (positive direction of Y axis)
    auto iterY = choiceX[p2.x].upper_bound(p2.y);
    if (iterY != choiceX[p2.x].end())
    {
      Point p3 = {p2.x, *iterY, calc_value(p2.x, *iterY, c)};
      Point p4 = {p1.x, p3.y, calc_value(p1.x, p3.y, c)};
      Point invp4 = invert(p4, base);

      // assert that there is no point on p4 -> p1
      iterY = choiceX[p1.x].upper_bound(p1.y);
      iterX = choiceY[p4.y].upper_bound(p4.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && (iterY == choiceX[p1.x].end() || *iterY > p4.y) && *iterX == p3.x && drawable(p1, p2, p3, p4, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, true, rot));
        cnt++;
      }
    }
    // Search bottom (negative direction of Y axis)
    iterY = choiceX[p2.x].lower_bound(p2.y);
    if (iterY != choiceX[p2.x].begin())
    {
      iterY--;
      Point p3 = {p2.x, *iterY, calc_value(p2.x, *iterY, c)};
      Point p4 = {p1.x, p3.y, calc_value(p1.x, p3.y, c)};
      Point invp4 = invert(p4, base);

      iterY = choiceX[p4.x].upper_bound(p4.y);
      iterX = choiceY[p4.y].upper_bound(p4.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && *iterY == p1.y && *iterX == p3.x && drawable(p1, p2, p3, p4, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, true, rot));
        cnt++;
      }
    }
  }

  /*
  Search left (negative direction of X axis)
  */

  iterX = choiceY[p1.y].lower_bound(p1.x);
  if (iterX != choiceY[p1.y].begin())
  {
    iterX--;
    Point p2 = {*iterX, p1.y, calc_value(*iterX, p1.y, c)};

    // search top (positive direction of Y axis)
    auto iterY = choiceX[p2.x].upper_bound(p2.y);
    if (iterY != choiceX[p2.x].end())
    {
      Point p3 = {p2.x, *iterY, calc_value(p2.x, *iterY, c)};
      Point p4 = {p1.x, p3.y, calc_value(p1.x, p3.y, c)};
      Point invp4 = invert(p4, base);

      iterY = choiceX[p1.x].upper_bound(p1.y);
      iterX = choiceY[p3.y].upper_bound(p3.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && (iterY == choiceX[p1.x].end() || *iterY > p4.y) && (iterX == choiceY[p3.y].end() || *iterX > p4.x) && drawable(p1, p2, p3, p4, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, true, rot));

        cnt++;
      }
    }

    // search bottom (negative direction of Y axis)
    iterY = choiceX[p2.x].lower_bound(p2.y);
    if (iterY != choiceX[p2.x].begin())
    {
      iterY--;
      Point p3 = {p2.x, *iterY, calc_value(p2.x, *iterY, c)};
      Point p4 = {p1.x, p3.y, calc_value(p1.x, p3.y, c)};
      Point invp4 = invert(p4, base);

      iterY = choiceX[p4.x].upper_bound(p4.y);
      iterX = choiceY[p3.y].upper_bound(p3.x);

      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && *iterY == p1.y && (iterX == choiceY[p3.y].end() || *iterX > p4.x) && drawable(p1, p2, p3, p4, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, true, rot));
        cnt++;
      }
    }
  }
  return false;
}

bool searchVert(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
                vector<vector<bool>> &lineHor, vector<vector<bool>> &lineVert,
                vector<vector<bool>> &C,
                Point p1, int c, int N,
                bool rot, int base, priority_queue<quad, vector<quad>, greater<quad>> &int_que, int &cnt, vector<vector<Point>> &cand)
{
  /*
   Search top (positive direction of Y axis)
  */
  auto iterY = choiceX[p1.x].upper_bound(p1.y);
  if (iterY != choiceX[p1.x].end())
  {
    Point p2 = {p1.x, *iterY, calc_value(p1.x, *iterY, c)};

    // Search right (positive direction of X axis)
    auto iterX = choiceY[p2.y].upper_bound(p2.x);
    if (iterX != choiceY[p2.y].end())
    {
      Point p3 = {*iterX, p2.y, calc_value(*iterX, p2.y, c)};
      Point p4 = {p3.x, p1.y, calc_value(p3.x, p1.y, c)};
      Point invp4 = invert(p4, base);

      // assert that there is no point on p4 -> p1
      iterY = choiceX[p4.x].upper_bound(p4.y);
      iterX = choiceY[p1.y].upper_bound(p1.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && *iterY == p3.y && (iterX == choiceY[p1.y].end() || *iterX > p4.x) && drawable(p1, p4, p3, p2, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, false, rot));
        cnt++;
      }
    }
    // Search left (negative direction of X axis)
    iterX = choiceY[p2.y].lower_bound(p2.x);
    if (iterX != choiceY[p2.y].begin())
    {
      iterX--;
      Point p3 = {*iterX, p2.y, calc_value(*iterX, p2.y, c)};
      Point p4 = {p3.x, p1.y, calc_value(p3.x, p1.y, c)};
      Point invp4 = invert(p4, base);

      // assert that there is no point on p4 -> p1
      iterY = choiceX[p4.x].upper_bound(p4.y);
      iterX = choiceY[p4.y].upper_bound(p4.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && *iterY == p3.y && *iterX == p1.x && drawable(p1, p4, p3, p2, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, false, rot));
        cnt++;
      }
    }
  }
  /*
   Search bottom (negative direction of Y axis)
  */
  iterY = choiceX[p1.x].lower_bound(p1.y);
  if (iterY != choiceX[p1.x].begin())
  {
    iterY--; // (90, 58)
    Point p2 = {p1.x, *iterY, calc_value(p1.x, *iterY, c)};

    // Search right (positive direction of X axis)
    auto iterX = choiceY[p2.y].upper_bound(p2.x); // (90, 50)
    // debug(p2);
    if (iterX != choiceY[p2.y].end())
    {
      Point p3 = {*iterX, p2.y, calc_value(*iterX, p2.y, c)};
      Point p4 = {p3.x, p1.y, calc_value(p3.x, p1.y, c)};
      Point invp4 = invert(p4, base);

      // assert that there is no point on p4 -> p1
      iterY = choiceX[p3.x].upper_bound(p3.y);
      iterX = choiceY[p1.y].upper_bound(p1.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && (iterY == choiceX[p3.x].end() || *iterY > p4.y) && (iterX == choiceY[p1.y].end() || *iterX > p4.x) && drawable(p1, p4, p3, p2, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, false, rot));

        cnt++;
      }
    }

    // Search left (negative direction of X axis)
    iterX = choiceY[p2.y].lower_bound(p2.x);
    if (iterX != choiceY[p2.y].begin())
    {
      iterX--;
      Point p3 = {*iterX, p2.y, calc_value(p2.y, *iterX, c)};
      Point p4 = {p3.x, p1.y, calc_value(p3.x, p1.y, c)};
      Point invp4 = invert(p4, base);

      // assert that there is no point on p4 -> p1
      iterY = choiceX[p3.x].upper_bound(p3.y);
      iterX = choiceY[p4.y].upper_bound(p4.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && (iterY == choiceX[p3.x].end() || *iterY > p4.y) && *iterX == p1.x && drawable(p1, p4, p3, p2, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, false, rot));
        cnt++;
      }
    }
  }
  return false;
}

bool searchVert(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
                vector<vector<bool>> &lineHor, vector<vector<bool>> &lineVert,
                vector<vector<bool>> &C,
                Point p1, int c, int N,
                bool rot, int base, priority_queue<quad> &int_que, int &cnt, vector<vector<Point>> &cand)
{
  /*
   Search top (positive direction of Y axis)
  */
  auto iterY = choiceX[p1.x].upper_bound(p1.y);
  if (iterY != choiceX[p1.x].end())
  {
    Point p2 = {p1.x, *iterY, calc_value(p1.x, *iterY, c)};

    // Search right (positive direction of X axis)
    auto iterX = choiceY[p2.y].upper_bound(p2.x);
    if (iterX != choiceY[p2.y].end())
    {
      Point p3 = {*iterX, p2.y, calc_value(*iterX, p2.y, c)};
      Point p4 = {p3.x, p1.y, calc_value(p3.x, p1.y, c)};
      Point invp4 = invert(p4, base);

      // assert that there is no point on p4 -> p1
      iterY = choiceX[p4.x].upper_bound(p4.y);
      iterX = choiceY[p1.y].upper_bound(p1.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && *iterY == p3.y && (iterX == choiceY[p1.y].end() || *iterX > p4.x) && drawable(p1, p4, p3, p2, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, false, rot));
        cnt++;
      }
    }

    // Search left (negative direction of X axis)
    iterX = choiceY[p2.y].lower_bound(p2.x);
    if (iterX != choiceY[p2.y].begin())
    {
      iterX--;
      Point p3 = {*iterX, p2.y, calc_value(*iterX, p2.y, c)};
      Point p4 = {p3.x, p1.y, calc_value(p3.x, p1.y, c)};
      Point invp4 = invert(p4, base);

      // assert that there is no point on p4 -> p1
      iterY = choiceX[p4.x].upper_bound(p4.y);
      iterX = choiceY[p4.y].upper_bound(p4.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && *iterY == p3.y && *iterX == p1.x && drawable(p1, p4, p3, p2, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, false, rot));
        cnt++;
      }
    }
  }

  /*
   Search bottom (negative direction of Y axis)
  */
  iterY = choiceX[p1.x].lower_bound(p1.y);
  if (iterY != choiceX[p1.x].begin())
  {
    iterY--;
    Point p2 = {p1.x, *iterY, calc_value(p1.x, *iterY, c)};

    // Search right (positive direction of X axis)
    auto iterX = choiceY[p2.y].upper_bound(p2.x);
    if (iterX != choiceY[p2.y].end())
    {
      Point p3 = {*iterX, p2.y, calc_value(*iterX, p2.y, c)};
      Point p4 = {p3.x, p1.y, calc_value(p3.x, p1.y, c)};
      Point invp4 = invert(p4, base);

      // assert that there is no point on p4 -> p1
      iterY = choiceX[p3.x].upper_bound(p3.y);
      iterX = choiceY[p1.y].upper_bound(p1.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && (iterY == choiceX[p3.x].end() || *iterY > p4.y) && (iterX == choiceY[p1.y].end() || *iterX > p4.x) && drawable(p1, p4, p3, p2, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, false, rot));
        cnt++;
      }
    }

    // Search left (negative direction of X axis)
    iterX = choiceY[p2.y].lower_bound(p2.x);
    if (iterX != choiceY[p2.y].begin())
    {
      iterX--;
      Point p3 = {*iterX, p2.y, calc_value(p2.y, *iterX, c)};
      Point p4 = {p3.x, p1.y, calc_value(p3.x, p1.y, c)};
      Point invp4 = invert(p4, base);

      // assert that there is no point on p4 -> p1
      iterY = choiceX[p3.x].upper_bound(p3.y);
      iterX = choiceY[p4.y].upper_bound(p4.x);
      if (((!rot && !C[p4.x][p4.y]) || (rot && invp4.x >= 0 && invp4.y >= 0 && invp4.x < N && invp4.y < N && !C[invp4.x][invp4.y])) && (iterY == choiceX[p3.x].end() || *iterY > p4.y) && *iterX == p1.x && drawable(p1, p4, p3, p2, lineHor, lineVert))
      {
        cand.push_back({p1, p2, p3, p4});
        int_que.push(quad(p4.value, cnt, false, rot));
        cnt++;
      }
    }
  }
  return false;
}

void search(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
            vector<set<int>> &choiceRotX, vector<set<int>> &choiceRotY,
            vector<vector<bool>> &lineHor, vector<vector<bool>> &lineVert,
            vector<vector<bool>> &lineRotHor, vector<vector<bool>> &lineRotVert,
            vector<vector<bool>> &C, priority_queue<Point, vector<Point>, greater<Point>> &que1, priority_queue<Point> &que2,
            int c, int N, int base, vector<vector<Point>> &ans)
{
  while (!que1.empty())
  {
    priority_queue<quad, vector<quad>, greater<quad>> int_que;
    int cnt = 0;
    vector<vector<Point>> cand;
    bool flg = false;
    vector<int> pattern = {0, 1, 2, 3};
    shuffle(pattern.begin(), pattern.end(), get_rand_mt);
    Point p1 = que1.top();
    if (get_rand_mt() % WIDTH == 0)
    {
      que2.push(p1);
      que1.pop();
      continue;
    }
    Point rotp1 = rotate(p1, base);
    // horizontal
    for (int i = 0; i < 4; i++)
    {
      if (pattern[i] == 0 && !flg)
      {
        // cout << 0 << endl;
        flg = searchHor(choiceX, choiceY,
                        lineHor, lineVert,
                        C, p1, c, N,
                        false, base,
                        int_que, cnt, cand);
      }
      // vertical
      if (pattern[i] == 1 && !flg)
      {
        flg = searchVert(choiceX, choiceY,
                         lineHor, lineVert,
                         C, p1, c, N,
                         false, base,
                         int_que, cnt, cand);
      }

      if (pattern[i] == 2 && !flg)
      {
        flg = searchHor(choiceRotX, choiceRotY,
                        lineRotHor, lineRotVert,
                        C, rotp1, c, N,
                        true, base,
                        int_que, cnt, cand);
      }

      if (pattern[i] == 3 && !flg)
      {
        flg = searchVert(choiceRotX, choiceRotY,
                         lineRotHor, lineRotVert,
                         C, rotp1, c, N,
                         true, base,
                         int_que, cnt, cand);
      }
      if (cnt > N_STORE)
      {
        break;
      }
    }
    if (!int_que.empty())
    {
      quad best = int_que.top();
      vector<Point> p = cand[best.n2];
      bool rot = best.n4;
      bool is_hor = best.n3;
      if (rot)
      {
        append_point(choiceRotX, choiceRotY,
                     choiceX, choiceY,
                     C, ans, que1,
                     p[0], p[1], p[2], p[3], rot, base);
        if (is_hor)
          draw_line(p[0], p[1], p[2], p[3], lineRotHor, lineRotVert);
        else
          draw_line(p[0], p[3], p[2], p[1], lineRotHor, lineRotVert);
      }
      else
      {
        append_point(choiceX, choiceY,
                     choiceRotX, choiceRotY,
                     C, ans, que1,
                     p[0], p[1], p[2], p[3], rot, base);
        if (is_hor)
          draw_line(p[0], p[1], p[2], p[3], lineHor, lineVert);
        else
          draw_line(p[0], p[3], p[2], p[1], lineHor, lineVert);
      }
    }

    // from left-top to right-bottom (using rotX coord) or opposit direction
    // from right-top to left-bottom (using rotY coord) or opposit direction
    if (cnt > 0)
      que2.push(p1);

    que1.pop();
  }
}

void search(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
            vector<set<int>> &choiceRotX, vector<set<int>> &choiceRotY,
            vector<vector<bool>> &lineHor, vector<vector<bool>> &lineVert,
            vector<vector<bool>> &lineRotHor, vector<vector<bool>> &lineRotVert,
            vector<vector<bool>> &C, priority_queue<Point> &que1, priority_queue<Point, vector<Point>, greater<Point>> &que2,
            int c, int N, int base, vector<vector<Point>> &ans)
{

  while (!que1.empty())
  {
    priority_queue<quad> int_que;
    int cnt = 0;
    vector<vector<Point>> cand;
    bool flg = false;
    vector<int> pattern = {0, 1, 2, 3};
    shuffle(pattern.begin(), pattern.end(), get_rand_mt);
    Point p1 = que1.top();
    Point rotp1 = rotate(p1, base);
    // cout << get_rand_mt() << endl;

    if (get_rand_mt() % WIDTH == 0)
    {
      que2.push(p1);
      que1.pop();
      continue;
    }
    // horizontal
    for (int i = 0; i < 4; i++)
    {
      if (pattern[i] == 0 && !flg)
        flg = searchHor(choiceX, choiceY,
                        lineHor, lineVert,
                        C, p1, c, N,
                        false, base,
                        int_que, cnt, cand);
      // vertical
      if (pattern[i] == 1 && !flg)
        flg = searchVert(choiceX, choiceY,
                         lineHor, lineVert,
                         C, p1, c, N,
                         false, base,
                         int_que, cnt, cand);

      if (pattern[i] == 2 && !flg)
        flg = searchHor(choiceRotX, choiceRotY,
                        lineRotHor, lineRotVert,
                        C, rotp1, c, N,
                        true, base,
                        int_que, cnt, cand);

      if (pattern[i] == 3 && !flg)
        flg = searchVert(choiceRotX, choiceRotY,
                         lineRotHor, lineRotVert,
                         C, rotp1, c, N,
                         true, base,
                         int_que, cnt, cand);
      if (cnt > N_STORE)
      {
        break;
      }
      // if (flg)
      // {
      //   break;
      // }
    }
    if (!int_que.empty())
    {
      quad best = int_que.top();
      vector<Point> p = cand[best.n2];

      bool rot = best.n4;
      bool is_hor = best.n3;
      if (rot)
      {
        append_point(choiceRotX, choiceRotY,
                     choiceX, choiceY,
                     C, ans, que1,
                     p[0], p[1], p[2], p[3], rot, base);
        if (is_hor)
          draw_line(p[0], p[1], p[2], p[3], lineRotHor, lineRotVert);
        else
          draw_line(p[0], p[3], p[2], p[1], lineRotHor, lineRotVert);
      }
      else
      {
        append_point(choiceX, choiceY,
                     choiceRotX, choiceRotY,
                     C, ans, que1,
                     p[0], p[1], p[2], p[3], rot, base);
        if (is_hor)
          draw_line(p[0], p[1], p[2], p[3], lineHor, lineVert);
        else
          draw_line(p[0], p[3], p[2], p[1], lineHor, lineVert);
      }
    }

    // from left-top to right-bottom (using rotX coord) or opposit direction
    // from right-top to left-bottom (using rotY coord) or opposit direction
    if (cnt > 0)
      que2.push(p1);

    que1.pop();
  }
}

int main()
{

  // read input
  int N, M, c, x, y;
  cin >> N >> M;
  vector<vector<bool>> C(N, vector<bool>(N, false));
  vector<vector<Point>> ans;

  int rotN = 2 * N - 1;
  int base = N - 1;
  vector<set<int>> choiceX(N, set<int>());
  vector<set<int>> choiceY(N, set<int>());
  vector<set<int>> choiceRotX(rotN + base, set<int>());
  vector<set<int>> choiceRotY(rotN + base, set<int>());
  vector<vector<bool>> lineHor(N, vector<bool>(N, false));
  vector<vector<bool>> lineVert(N, vector<bool>(N, false));
  vector<vector<bool>> lineRotHor(rotN + base, vector<bool>(rotN + base, false));
  vector<vector<bool>> lineRotVert(rotN + base, vector<bool>(rotN + base, false));

  priority_queue<Point, vector<Point>, greater<Point>> que1;
  priority_queue<Point> que2;
  vector<Point> init(M + 1);
  c = (N - 1) / 2;
  for (int i = 1; i <= M; i++)
  {
    cin >> x >> y;
    Point p;
    p.x = x;
    p.y = y;
    p.value = calc_value(x, y, c);
    Point rot = rotate(p, base);
    choiceX[x].insert(y);
    choiceY[y].insert(x);
    choiceRotX[rot.x].insert(rot.y);
    choiceRotY[rot.y].insert(rot.x);

    C[x][y] = true;
    que1.push(p);
    init[i] = p;
  }

  while (!(que1.empty() && que2.empty()))
  {
    search(choiceX, choiceY,
           choiceRotX, choiceRotY,
           lineHor, lineVert,
           lineRotHor, lineRotVert,
           C, que1, que2,
           c, N, base, ans);
    search(choiceX, choiceY,
           choiceRotX, choiceRotY,
           lineHor, lineVert,
           lineRotHor, lineRotVert,
           C, que2, que1,
           c, N, base, ans);
    if (!(que1.empty() && que2.empty()))
    {
      for (int i = 1; i <= M; i++)
      {
        que2.push(init[i]);
        que1.push(init[i]);
      }
      for (int i = 0; i < ans.size(); i++)
      {
        que2.push(ans[i][3]);
        que1.push(ans[i][3]);
      }
    }
  }

  cout << ans.size() << endl;
  for (vector<std::vector<P>>::size_type i = 0; i < ans.size(); i++)
  {
    output(ans[i][3], ans[i][0], ans[i][1], ans[i][2]);
  }
  return 0;
}
