#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
    // cr�e la fen�tre
    sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    // chargement des ressources, initialisation des �tats OpenGL, ...

    // la boucle principale
    bool running = true;
    while (running)
    {
        // gestion des �v�nements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // on stoppe le programme
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // on ajuste le viewport lorsque la fen�tre est redimensionn�e
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        // effacement les tampons de couleur/profondeur
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // dessin...

        // termine la trame courante (en interne, �change les deux tampons de rendu)
        window.display();
    }

    // lib�ration des ressources...

    return 0;
}