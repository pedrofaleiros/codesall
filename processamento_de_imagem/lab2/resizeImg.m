function imgRes = resizeImg(img, option)

  if strcmp(option, 'dilata')
    imgRes = dilata(img);
  elseif strcmp(option, 'comprime')
    imgRes = comprime(img);
  else
    error('escolha "dilata" ou "comprime"');
  endif

end

