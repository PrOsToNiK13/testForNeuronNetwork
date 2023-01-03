#ifndef PAINTER_H
#define PAINTER_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QWidget>

class painter : public QWidget
{
    Q_OBJECT
public:
    painter()
    {
        pixmap_ = QPixmap( 600, 600);
        pixmap_.fill( Qt::black );
        pen_ = QPen( QBrush( Qt::white ), 50 );
        pen_.setCapStyle(Qt::RoundCap);
    }
     QPixmap pixmap_;

protected:
    void mousePressEvent( QMouseEvent * e )
    {
        if ( e->button() == Qt::LeftButton )
        {
            QPainter p( &pixmap_ );
            p.setRenderHint(QPainter::Antialiasing, false);
            p.setPen( pen_ );
            p.drawPoint( e->pos() );
            p.end();

            lastPoint_ = e->pos();

            update();
        }
    }

    void mouseMoveEvent( QMouseEvent * e )
    {
        if ( e->buttons() & Qt::LeftButton )
        {
            QPainter p( &pixmap_ );
            p.setRenderHint(QPainter::Antialiasing, false);
            p.setPen( pen_ );
            p.drawLine( lastPoint_, e->pos() );
            p.end();

            lastPoint_ = e->pos();

            update();
        }
    }

    void paintEvent( QPaintEvent * )
    {
        QPainter p( this );
        p.setCompositionMode( QPainter::CompositionMode_Source );
        p.drawPixmap( QPoint(), pixmap_ );
    }

private:
    QPen pen_;
    QPoint lastPoint_;
};

#endif // PAINTER_H
