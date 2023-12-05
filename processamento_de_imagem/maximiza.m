function img = maximiza(x)

    x = double(x);
    x = x/255;

    [l, c, aux] = size(x);

    for i = 1:l

        #mostra quanto % ja foi
        i / l

        for j = 1:c
            index = imaior(x(i, j, 1), x(i, j, 2), x(i, j, 3));

            if index == 1
                img(i, j, 1) = x(i, j, 1);
                img(i, j, 2) = 0;
                img(i, j, 3) = 0;
            elseif index == 2
                img(i, j, 2) = x(i, j, 2);
                img(i, j, 1) = 0;
                img(i, j, 3) = 0;
            elseif index == 3
                img(i, j, 3) = x(i, j, 3);
                img(i, j, 2) = 0;
                img(i, j, 1) = 0;
            endif
        endfor
    endfor
