int exp(int a, int b)
{
	if (b == 0)
		return 1;
	int x = exp(a, (b / 2));
	x *= x;
	x %= mod;
	if (b % 2)
		x *= a;
	x %= mod;
	return x;
}

int inverse(int a)
{
	return exp(a, mod - 2);
}

int fac1(int z)
{
	int er = 1;
	rep(i, 1, z + 1)
	{
		er *= i;
		er %= mod;
	}
	return er;
}

int fac(int n, int a)
{
	int er = 1;
	rep(i, (n - a + 1), n + 1)
	{
		er *= i;
		er %= mod;
	}
	er *= inverse(fac1(a));
	er %= mod;
	return er;
}

int fact[N];

void pre()
{
	fact[0] = 1;
	rep(i, 1, N)
	{
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}
}
