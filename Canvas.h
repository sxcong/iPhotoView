/**
 * QPhotoView canvas graphics item for viewer widget.
 *
 * License: GPL V2. See file COPYING for details.
 *
 * Author:  Stefan Hundhammer <Stefan.Hundhammer@gmx.de>
 */

#ifndef Canvas_h
#define Canvas_h

#include <QGraphicsPixmapItem>
#include <QCursor>

class PhotoView;
class QGraphicsSceneMouseEvent;
class GraphicsItemPosAnimation;


/**
 * Canvas for PhotoView: A graphics item that shows the photo.
 */
class Canvas: public QGraphicsPixmapItem
{
public:

    /**
     * Constructor.
     */
    Canvas( PhotoView * parent );

    /**
     * Destructor.
     */
    virtual ~Canvas();

    /**
     * Return the current size.
     */
    QSize size() const;

    /**
     * Clear the current pixmap.
     */
    void clear();

    /**
     * Center inside the viewport of the PhotoView parent if this canvas is
     * smaller than the viewport.
     */
    void center( const QSize & parentSize );

    /**
     * Return 'true' if panning is in progress, i.e. if the user currently
     * drags (scrolls) the image.
     */
    bool panning() const { return _panning; }

    /**
     * Fix the canvas position: If the canvas is smaller than the PhotoView's
     * viewport, center it. If it is larger in either dimension, make sure
     * there are no black borders in that dimension.
     *
     * Any necessary position change is animated unless 'animate' is false.
     */
    void fixPosAnimated( bool animate = true );

    /**
     * Return the parent photo view.
     */
    PhotoView * photoView() const { return _photoView; }

    /**
     * Hide the cursor. Called when the idle timer times out.
     */
    void hideCursor();

    /**
     * Show the cursor.
     */
    void showCursor();


protected:

    //
    // Event handlers, all reimplemented from QGraphicsItem
    //

    /**
     * Pan (scroll) the image with left mouse button pressed
     */
    virtual void mouseMoveEvent	  ( QGraphicsSceneMouseEvent * event ) Q_DECL_OVERRIDE;

    /**
     * Prepare panning
     */
    virtual void mousePressEvent  ( QGraphicsSceneMouseEvent * event ) Q_DECL_OVERRIDE;

    /**
     * Clan up after panning
     */
    virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent * event ) Q_DECL_OVERRIDE;

    /**
     * Zoom in (double click left) or out (double click right)
     */
    virtual void mouseDoubleClickEvent ( QGraphicsSceneMouseEvent * event ) Q_DECL_OVERRIDE;

    /**
     * Mouse wheel: load the next or the previous image
     */
  //  virtual void wheelEvent( QGraphicsSceneWheelEvent * event ) Q_DECL_OVERRIDE;

    /**
     * Context menu (click right)
     */
    //virtual void contextMenuEvent( QGraphicsSceneContextMenuEvent * event ) Q_DECL_OVERRIDE;

private:
    QMenu *buildHelpMenu(bool addIcon, QWidget *parent);
private:

    PhotoView *			_photoView = nullptr;
    bool			_panning = nullptr;
    GraphicsItemPosAnimation *	_animation = nullptr;
    QCursor			_cursor;
};


#endif // Canvas_h
