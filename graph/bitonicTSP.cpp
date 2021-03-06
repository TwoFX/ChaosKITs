// Laufzeit: O(n^2)
vector<vector<double>> dp, dist; // Entfernungen zwischen Punkten.

double get(int p1, int p2) {
  int v = max(p1, p2) + 1;
  if (v == dist.size()) return dist[p1][v - 1] + dist[p2][v - 1];
  if (dp[p1][p2] >= 0.0) return dp[p1][p2];
  double tryLR = dist[p1][v] + get(v, p2);
  double tryRL = dist[p2][v] + get(p1, v);
  return dp[p1][p2] = min(tryLR, tryRL);
}

void bitonicTour() {
  dp.assign(dist.size(), vector<double>(dist.size(), -1));
  get(0, 0); // return dp[0][0]; // Länger der Tour
  vector<int> lr = {0}, rl = {0};
  for (int p1 = 0, p2 = 0, v; (v = max(p1, p2) + 1) < dist.size();) {
    if (dp[p1][p2] == dist[p1][v] + dp[v][p2]) {
      lr.push_back(v); p1 = v;
    } else {
      rl.push_back(v); p2 = v;
	}}
  lr.insert(lr.end(), rl.rbegin(), rl.rend()); // Tour, Knoten 0 doppelt.
}
