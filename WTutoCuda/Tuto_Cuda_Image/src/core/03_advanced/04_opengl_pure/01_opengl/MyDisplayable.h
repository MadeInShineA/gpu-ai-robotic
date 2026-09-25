#pragma once

#include "Displayable_A.h"

#include "Variateur.cu.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

/**
 * <pre>
 * Quoi 	:	Code OpenGL standard (une scene 3D par exemple
 * But		:	Utiliser l'api Imgage et du code OpenGL standard, par exemple dans 2 fen�tre diff�rents
 * Technique    :	Utiliser les viewers de l'api image qui se charge du fen�trage (freeglut, x11, qt, ...)
 * Consequence	:	Pas de trace de freeglut par exemple
 * 			En particulier, pas de trace de idel de freeglut qui s'occupe des animations
 * </pre>
 */
class MyDisplayable : public Displayable_A
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    MyDisplayable();
    virtual ~MyDisplayable();

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    /**
     * Override
     */
    void init(Panel_A &panel);

    /**
     * Override
     */
    void reshape(Panel_A &panel, int w, int h);

    /**
     * Override
     */
    void display(Panel_A &panel);

    /**
     * Override
     */
    void release(Panel_A &panel);

    /**
     * Override
     */
    void animationStep(Panel_A &panel, bool &isNeedUpdate);

    // ---------------------------------
    // private
    // ---------------------------------

  private:
    void drawScene3D();

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Tools
    float py;                   // para animation
    Variateur<float> variateur; // pour animation
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
