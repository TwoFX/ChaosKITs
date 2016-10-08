// Laufzeit: O(log (n) + log(p))
ll multInv(ll n, ll p) {
	ll x, y;
	extendedEuclid(n, p, x, y); // Implementierung von oben.
	x += ((x / p) + 1) * p;
	return x % p;
}
