function img_output = ajustaContraste(img, type)

    img_media = mean(img(:));

    gamma_escurecer = 2;
    gamma_clarear = 0.5;

    switch type
        case 'log'
            if img_media > 0.5
                c = 0.5;
                img_output = exp(c * img) - 1;
                message = 'escurecendo log inverso'
            else
                c = 2;
                img_output = c * log(1 + img);
                message = 'clareando log'
            end
        case 'gamma'
            if img_media > 0.5
                img_output = img .^ gamma_escurecer;
                message = 'escurecendo gamma'
            else
                img_output = img .^ gamma_clarear;
                message = 'clareando gamma'
            end
        otherwise
            error('erro');
    end

    #img_output = uint8(img_output * 255);
end

