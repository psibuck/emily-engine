//
//  Paddle.cpp
//  Emily
//
//  Created by Archie Buck on 02/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Paddle.h"

#include <SFML/Graphics.hpp>

//--
// Constructor
//--
Paddle::Paddle( const float x_in, const float y_in ) : EMILY::Entity( 'padl' ), x( x_in ), y( y_in )
{
    paddle = std::make_unique<sf::RectangleShape>( sf::Vector2f( width, height ));
    paddle->setPosition( x, y );
    paddle->setFillColor( sf::Color( 255, 255, 255 ));
}

//--
// Draws the paddle to the screen
//--
void Paddle::draw(sf::RenderWindow *window) const
{
    window->draw( *paddle );
}

//--
// Updates the paddle data
//--
void Paddle::update( void )
{
    if( in_motion )
    {
        if( current_direction == DIRECTION::UP )
        {
            move_up();
        }
        else
        {
            move_down();
        }
    }
}


//--
// Handles key press events
//--
void Paddle::handle_keypress(const sf::Keyboard::Key key)
{
    switch( key )
    {
        case sf::Keyboard::Up:
        case sf::Keyboard::Q:
            in_motion = true;
            current_direction = DIRECTION::UP;
            break;
        case sf::Keyboard::Down:
        case sf::Keyboard::A:
            in_motion = true;
            current_direction = DIRECTION::DOWN;
            break;
        default:
            break;
    }
}

//--
// Handle key release events
//--
void Paddle::handle_key_release(const sf::Keyboard::Key key)
{
    switch( key )
    {
        case sf::Keyboard::Up:
        case sf::Keyboard::Q:
            if( in_motion && current_direction == DIRECTION::UP )
            {
                in_motion = false;
            }
            break;
        case sf::Keyboard::Down:
        case sf::Keyboard::A:
            if( in_motion && current_direction == DIRECTION::DOWN )
            {
                in_motion = false;
            }
            break;
        default:
            break;
    }
}

//--
// Moves the paddle up as long as it's within the confines
//--
void Paddle::move_up( void )
{
    paddle->setPosition( paddle->getPosition().x, paddle->getPosition().y - speed );
}

//--
// Moves the paddle down as long as it's within the confines
//--
void Paddle::move_down( void )
{
    paddle->setPosition( paddle->getPosition().x, paddle->getPosition().y + speed );
}

//--
// Returns the pointer to the SFML object
//--
sf::RectangleShape *Paddle::get_paddle()
{
    return paddle.get();
}


