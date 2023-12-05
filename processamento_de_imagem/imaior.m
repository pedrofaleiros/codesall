function index = imaior(r, g, b)

  maior = r;
  index = 1;

  if maior < g
    maior = g;
    index = 2;
  endif

  if maior < b
    maior = b;
    index = 3;
  endif

