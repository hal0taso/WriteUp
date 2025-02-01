// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <random>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// random_device get_rand_dev;
int N_STORE = 10;
int SEED = 1000;

typedef struct Point
{
  int x;
  int y;
  int value;

  Point() {}

  Point(int _x, int _y, int _value)
  {
    x = _x;
    y = _y;
    value = _value;
  }

  bool operator<(const struct Point &other) const
  {
    return value < other.value;
  }

  bool operator>(const struct Point &other) const
  {
    return value > other.value;
  }
} Point;

typedef struct Rect
{
  Point p1, p2, p3, p4;
  bool rot;
  int min_x, min_y, max_x, max_y;
  int value;

  Rect() {}
  Rect(Point &_p1, Point &_p2, Point &_p3, Point &_p4, bool _rot)
  {
    p1 = _p1;
    p2 = _p2;
    p3 = _p3;
    p4 = _p4;
    rot = _rot;
    min_x = min({_p1.x, _p2.x, _p3.x, _p4.x});
    min_y = min({_p1.y, _p2.y, _p3.y, _p4.y});
    max_x = max({_p1.x, _p2.x, _p3.x, _p4.x});
    max_y = max({_p1.y, _p2.y, _p3.y, _p4.y});
    if (!(p1.x == p4.x && p1.y == p4.y))
      value = p4.value;
    else
      value = 0;
  }
  bool operator<(const struct Rect &other) const
  {
    return p4.value < other.p4.value;
  }

  bool operator>(const struct Rect &other) const
  {
    return p4.value > other.p4.value;
  }

} Rect;

typedef struct Cand
{
  vector<Rect> v;
  int value;
  bool operator<(const struct Cand &other) const
  {
    // Your priority logic goes here
    return value < other.value;
  }

  bool operator>(const struct Cand &other) const
  {
    return value > other.value;
  }
} Cand;

bool intersect(Rect &r1, Rect &r2)
{
  if (r1.rot == r1.rot)
  {
    if (r1.min_x <= r2.min_x && r2.min_x < r1.max_x)
    {
      if (r1.min_y == r2.min_y || r1.min_y == r2.max_y || r1.max_y == r2.min_y || r1.max_y == r2.max_y)
      {
        return true;
      }
    }
    if (r1.min_y <= r2.min_y && r2.min_y < r1.max_y)
    {
      if (r1.min_x == r2.min_x || r1.min_x == r2.max_x || r1.max_x == r2.min_x || r1.max_x == r2.max_x)
      {
        return true;
      }
    }
  }
  return false;
}

Point rotate(Point &a, int base)
{
  Point b = Point(a.x + a.y + base, a.x - a.y + base, a.value);
  return b;
}

Point invert(Point &a, int base)
{
  Point b = Point((a.x + a.y) / 2 - base, (a.x - a.y) / 2, a.value);
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
                  Point &p1, Point &p2, Point &p3, Point &p4, bool rot, int base)
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

bool judgeC(vector<vector<bool>> &C, Point &p, bool rot, int N, int base)
{
  if (rot)
  {
    Point invp = invert(p, base);
    if (invp.x >= 0 && invp.y >= 0 && invp.x < N && invp.y < N)
      return !C[invp.x][invp.y];
  }
  else
  {
    return !C[p.x][p.y];
  }
  return false;
}

// Right - Up - Left - Down
Rect searchRULD(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
                vector<vector<bool>> &lineHor, vector<vector<bool>> &lineVert,
                vector<vector<bool>> &C,
                Point p1, int c, int N,
                bool rot, int base)
{
  auto iterX = choiceY[p1.y].upper_bound(p1.x);
  if (iterX != choiceY[p1.y].end())
  {
    Point p2 = Point(*iterX, p1.y, calc_value(*iterX, p1.y, c));
    // Search top (positive direction of Y axis)
    auto iterY = choiceX[p2.x].upper_bound(p2.y);
    if (iterY != choiceX[p2.x].end())
    {
      Point p3 = Point(p2.x, *iterY, calc_value(p2.x, *iterY, c));
      Point p4 = Point(p1.x, p3.y, calc_value(p1.x, p3.y, c));
      Point invp4 = invert(p4, base);

      // assert that there is no point on p4 -> p1
      iterY = choiceX[p1.x].upper_bound(p1.y);
      iterX = choiceY[p4.y].upper_bound(p4.x);
      bool flgVert = (iterY == choiceX[p1.x].end() || *iterY > p4.y);
      bool flgHor = (*iterX == p3.x);
      bool flgDraw = drawable(p1, p2, p3, p4, lineHor, lineVert);
      bool flgC = judgeC(C, p4, rot, N, base);

      if (flgC && flgVert && flgHor && flgDraw)
      {
        return Rect(p1, p2, p3, p4, rot);
      }
    }
  }
  return Rect(p1, p1, p1, p1, rot);
}

// Right - Down - Left - Up
Rect searchRDLU(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
                vector<vector<bool>> &lineHor, vector<vector<bool>> &lineVert,
                vector<vector<bool>> &C,
                Point p1, int c, int N,
                bool rot, int base)
{
  auto iterX = choiceY[p1.y].upper_bound(p1.x);
  if (iterX != choiceY[p1.y].end())
  {
    Point p2 = Point(*iterX, p1.y, calc_value(*iterX, p1.y, c));

    // Search bottom (negative direction of Y axis)
    auto iterY = choiceX[p2.x].lower_bound(p2.y);
    if (iterY != choiceX[p2.x].begin())
    {
      iterY--;
      Point p3 = Point(p2.x, *iterY, calc_value(p2.x, *iterY, c));
      Point p4 = Point(p1.x, p3.y, calc_value(p1.x, p3.y, c));
      Point invp4 = invert(p4, base);

      iterY = choiceX[p4.x].upper_bound(p4.y);
      iterX = choiceY[p4.y].upper_bound(p4.x);

      bool flgVert = (*iterY == p1.y);
      bool flgHor = (*iterX == p3.x);
      bool flgDraw = drawable(p1, p2, p3, p4, lineHor, lineVert);
      bool flgC = judgeC(C, p4, rot, N, base);

      if (flgC && flgVert && flgHor && flgDraw)
      {
        return Rect(p1, p2, p3, p4, rot);
      }
    }
  }
  return Rect(p1, p1, p1, p1, rot);
}

Rect searchLURD(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
                vector<vector<bool>> &lineHor, vector<vector<bool>> &lineVert,
                vector<vector<bool>> &C,
                Point p1, int c, int N,
                bool rot, int base)
{
  /*
  Search left (negative direction of X axis)
  */

  auto iterX = choiceY[p1.y].lower_bound(p1.x);
  if (iterX != choiceY[p1.y].begin())
  {
    iterX--;
    Point p2 = Point(*iterX, p1.y, calc_value(*iterX, p1.y, c));

    // search top (positive direction of Y axis)
    auto iterY = choiceX[p2.x].upper_bound(p2.y);
    if (iterY != choiceX[p2.x].end())
    {
      Point p3 = Point(p2.x, *iterY, calc_value(p2.x, *iterY, c));
      Point p4 = Point(p1.x, p3.y, calc_value(p1.x, p3.y, c));
      Point invp4 = invert(p4, base);

      iterY = choiceX[p1.x].upper_bound(p1.y);
      iterX = choiceY[p3.y].upper_bound(p3.x);

      bool flgVert = (iterY == choiceX[p1.x].end() || *iterY > p4.y);
      bool flgHor = (iterX == choiceY[p3.y].end() || *iterX > p4.x);
      bool flgDraw = drawable(p1, p2, p3, p4, lineHor, lineVert);
      bool flgC = judgeC(C, p4, rot, N, base);

      if (flgC && flgVert && flgHor && flgDraw)
      {
        return Rect(p1, p2, p3, p4, rot);
      }
    }
  }
  return Rect(p1, p1, p1, p1, rot);
}

Rect searchLDRU(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
                vector<vector<bool>> &lineHor, vector<vector<bool>> &lineVert,
                vector<vector<bool>> &C,
                Point p1, int c, int N,
                bool rot, int base)
{
  /*
  Search left (negative direction of X axis)
  */

  auto iterX = choiceY[p1.y].lower_bound(p1.x);
  if (iterX != choiceY[p1.y].begin())
  {
    iterX--;
    Point p2 = Point(*iterX, p1.y, calc_value(*iterX, p1.y, c));
    // search bottom (negative direction of Y axis)
    auto iterY = choiceX[p2.x].lower_bound(p2.y);
    if (iterY != choiceX[p2.x].begin())
    {
      iterY--;
      Point p3 = Point(p2.x, *iterY, calc_value(p2.x, *iterY, c));
      Point p4 = Point(p1.x, p3.y, calc_value(p1.x, p3.y, c));
      Point invp4 = invert(p4, base);

      iterY = choiceX[p4.x].upper_bound(p4.y);
      iterX = choiceY[p3.y].upper_bound(p3.x);

      bool flgVert = (*iterY == p1.y);
      bool flgHor = (iterX == choiceY[p3.y].end() || *iterX > p4.x);
      bool flgDraw = drawable(p1, p2, p3, p4, lineHor, lineVert);
      bool flgC = judgeC(C, p4, rot, N, base);

      if (flgC && flgVert && flgHor && flgDraw)
      {
        return Rect(p1, p2, p3, p4, rot);
      }
    }
  }
  return Rect(p1, p1, p1, p1, rot);
}

Rect searchRect(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
                vector<set<int>> &choiceRotX, vector<set<int>> &choiceRotY,
                vector<vector<bool>> &lineHor, vector<vector<bool>> &lineVert,
                vector<vector<bool>> &lineRotHor, vector<vector<bool>> &lineRotVert,
                vector<vector<bool>> &C, Point p1, int c, int N, int base,
                int pattern)
{
  Rect r;
  Point rotp1 = rotate(p1, base);
  if (pattern == 0)
  {
    r = searchRULD(choiceX, choiceY,
                   lineHor, lineVert,
                   C, p1, c, N, false, base);
  }
  if (pattern == 1)
  {
    r = searchRDLU(choiceX, choiceY,
                   lineHor, lineVert,
                   C, p1, c, N, false, base);
  }
  if (pattern == 2)
  {
    r = searchLURD(choiceX, choiceY,
                   lineHor, lineVert,
                   C, p1, c, N, false, base);
  }
  if (pattern == 3)
  {
    r = searchLDRU(choiceX, choiceY,
                   lineHor, lineVert,
                   C, p1, c, N, false, base);
  }
  if (pattern == 4)
  {
    r = searchRULD(choiceRotX, choiceRotY,
                   lineRotHor, lineRotVert,
                   C, rotp1, c, N, true, base);
  }
  if (pattern == 5)
  {
    r = searchRDLU(choiceRotX, choiceRotY,
                   lineRotHor, lineRotVert,
                   C, rotp1, c, N, true, base);
  }
  if (pattern == 6)
  {
    r = searchLURD(choiceRotX, choiceRotY,
                   lineRotHor, lineRotVert,
                   C, rotp1, c, N, true, base);
  }
  if (pattern == 7)
  {
    r = searchLDRU(choiceRotX, choiceRotY,
                   lineRotHor, lineRotVert,
                   C, rotp1, c, N, true, base);
  }
  return r;
}

bool success(Rect &r, Point &p1, int base)
{
  Point rotp1 = rotate(p1, base);

  if (r.rot && r.p4.x == rotp1.x && r.p4.y == rotp1.y)
  {
    return false;
  }
  if (!r.rot && r.p4.x == p1.x && r.p4.y == p1.y)
  {
    return false;
  }
  return true;
}

void search_by_queue(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
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
    mt19937_64 get_rand_mt(SEED);
    vector<int> pattern = {0, 1, 2, 3, 4, 5, 6, 7};
    shuffle(pattern.begin(), pattern.end(), get_rand_mt);
    Point p1 = que1.top();
    Point rotp1 = rotate(p1, base);
    // horizontal
    if (get_rand_mt() % 3 == 0)
    {
      que2.push(p1);
      que1.pop();
      continue;
    }

    for (int i = 0; i < 8; i++)
    {
      Rect r = searchRect(choiceX, choiceY,
                          choiceRotX, choiceRotY,
                          lineHor, lineVert,
                          lineRotHor, lineRotVert,
                          C, p1, c, N, base, i);

      // vertical
      if (success(r, p1, base))
      {
        cand.push_back({r.p1, r.p2, r.p3, r.p4});
        int_que.push(quad(r.p4.value, cnt, true, r.rot));
        cnt++;
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

void search_by_queue(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
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
    mt19937_64 get_rand_mt(SEED);
    vector<int> pattern = {0, 1, 2, 3, 4, 5, 6, 7};
    shuffle(pattern.begin(), pattern.end(), get_rand_mt);
    Point p1 = que1.top();
    Point rotp1 = rotate(p1, base);
    // horizontal
    if (get_rand_mt() % 3 == 0)
    {
      que2.push(p1);
      que1.pop();
      continue;
    }
    for (int i = 0; i < 8; i++)
    {
      Rect r = searchRect(choiceX, choiceY,
                          choiceRotX, choiceRotY,
                          lineHor, lineVert,
                          lineRotHor, lineRotVert,
                          C, p1, c, N, base, i);

      if (success(r, p1, base))
      {
        cand.push_back({r.p1, r.p2, r.p3, r.p4});
        int_que.push(quad(r.p4.value, cnt, true, r.rot));
        cnt++;
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
        // else
        //   draw_line(p[0], p[3], p[2], p[1], lineRotHor, lineRotVert);
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

void search_by_tree(vector<set<int>> &choiceX, vector<set<int>> &choiceY,
                    vector<set<int>> &choiceRotX, vector<set<int>> &choiceRotY,
                    vector<vector<bool>> &lineHor, vector<vector<bool>> &lineVert,
                    vector<vector<bool>> &lineRotHor, vector<vector<bool>> &lineRotVert,
                    vector<vector<bool>> &C, vector<Point> init,
                    int c, int N, int base, vector<vector<Point>> &ans)
{
  int SEARCH_DEPTH = 2;
  priority_queue<Cand> cand;
  vector<vector<Cand>> m;
  vector<vector<bool>> flg;

  m.resize(8 * (init.size() + ans.size()));
  flg.resize(8 * (init.size() + ans.size()));

  for (int i = 0; i < m.size(); i++)
  {
    m[i].resize(8 * (init.size() + ans.size() + 1));
    flg[i].resize(8 * (init.size() + ans.size() + 1, false));
  }

  for (int i = 0; i < init.size() + ans.size(); i++)
  {
    for (int j = 0; j < init.size() + ans.size() + 1; j++)
    {
      Point p1;
      if (i < init.size())
        p1 = init[i];
      else
        p1 = ans[i - init.size()][3]; // p4
      for (int pattern1 = 0; pattern1 < 8; pattern1++)
      {
        for (int pattern2 = 0; pattern2 < 8; pattern2++)
        {
          Rect r1 = searchRect(choiceX, choiceY,
                               choiceRotX, choiceRotY,
                               lineHor, lineVert,
                               lineRotHor, lineRotVert,
                               C, p1, c, N, base, pattern1);
          Point p2;
          if (success(r1, p1, base))
          {
            if (j < init.size())
              p2 = init[i];
            else if (j < init.size() + ans.size())
              p2 = ans[i - init.size()][3]; // p4
            else
              p2 = r1.p4;
          }
          else
            continue;

          Rect r2 = searchRect(choiceX, choiceY,
                               choiceRotX, choiceRotY,
                               lineHor, lineVert,
                               lineRotHor, lineRotVert,
                               C, p2, c, N, base, pattern2);

          Cand c;
          if (success(r2, p2, base))
          {
            c.v = {r1, r2};
            c.value = r1.value + r2.value;
          }
          else
          {
            c.v = {r1};
            c.value = r1.value + r2.value;
          }
          cand.push(c);
        }
      }
    }
  }
  Cand best = cand.top();
  for (int i = 0; i < best.v.size(); i++)
  {
    Rect r = best.v[i];
    bool rot = r.rot;
    if (rot)
    {
      append_point(choiceRotX, choiceRotY,
                   choiceX, choiceY,
                   C, ans,
                   r.p1, r.p2, r.p3, r.p4, rot, base);
    }
    else
    {
      append_point(choiceX, choiceY,
                   choiceRotX, choiceRotY,
                   C, ans,
                   r.p1, r.p2, r.p3, r.p4, rot, base);
    }
  }
}
void append_rect()
{
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
    Point p = Point(x, y, calc_value(x, y, c));
    Point rot = rotate(p, base);
    choiceX[x].insert(y);
    choiceY[y].insert(x);
    choiceRotX[rot.x].insert(rot.y);
    choiceRotY[rot.y].insert(rot.x);

    C[x][y] = true;
    que2.push(p);
    init[i] = p;
  }
  int tmp = 1;
  // while (tmp > 0)
  // {
  //   tmp = search_tree();
  // }
  while (!(que1.empty() && que2.empty()))
  {

    search_by_queue(choiceX, choiceY,
                    choiceRotX, choiceRotY,
                    lineHor, lineVert,
                    lineRotHor, lineRotVert,
                    C, que1, que2,
                    c, N, base, ans);
    search_by_queue(choiceX, choiceY,
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
  for (vector<std::vector<Point>>::size_type i = 0; i < ans.size(); i++)
  {
    output(ans[i][3], ans[i][0], ans[i][1], ans[i][2]);
  }
  return 0;
}
