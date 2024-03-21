# Cub3d
42SHOOL_PROJECT


/*First step*/

- Un main propre qui appelle 3 grande fonction qui refletent les etapes du projet:
----------------------------------
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	ft_parsing(ac, av, &data);
	ft_start_mlx(data);
	ft_clear_data(&data);
	return (EXIT_SUCCESS);
}
----------------------------------
c'est top!

-> dans le parsing on trouve : des petites fn de check qui sont toutes courtes
et qui respectent la one single role rule!


-> dans le start mlx: all mlx functions are called here
    player position initilisation
    texture creation :
        initialisation du pointeur mlx
        ft_xpm_file_and_addr()-> what does this function do?
        adding textures: north*south*west*east*
    checking for mlx ok or not
    printing the map (raycasting ou lancer de rayon)
        check horizontal sur les x
        check vertical sur les y
        _______ c'est le lancer de rayon________
        l'angle du rayon est la direction ont stockés dans la structure 
        selon quel critere on decide de choisir vertical ou horizontal ?
        decide horizontal ou vertical ? pas trop clair
        print 3d une fois nous savons quoi faire?
        incrementation de l'angle / rayon ...
        renderring
    key_events (lesdeplacement)
    mlx loop

-> clear data : free de la memoire allouée


/*note 

nous sommes sans un repere x et y
nous avons comme objectif de colorer pixel par pixel les differents points de ce repere.
la couleur du pixel depend de sa position.
---> basique lol 😂 

l'origine du repere ne l'est plus car notre angle de regard a change et nous avons maintenant un player qui; lui est la reference de  calcul et de representation des pixel sur l'ecran.

Questions:
un mur est un 1 mais c'est combien de pixel?

nous avons deux chois
    sol : sable par exp
    ciel : bleu par exp
        ecran en deux  --------------------------------------------+
                    
                                        ciel

                        -------------------------------------------+

                                        sol

                        --------------------------------------------+

    sur cette couche, nous construisons les murs,

    ou bien; une seule couche!
                        --------------------------------------------+
                    
                        mur       mur         ciel

                        ---------------------------------ciel----------+ c'est plus simple selon Adriano
                            mur mur                 mur    mur
                                mur mur mur mur mur sol
                                        sol

                        --------------------------------------------+




