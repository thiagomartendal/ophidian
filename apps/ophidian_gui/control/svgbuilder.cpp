#include "svgbuilder.h"

SVGBuilder::SVGBuilder(double width, double height) :
    mHeader("<svg version=\"1.1\" baseProfile=\"full\" width=\"")
{
    mHeader += QString::number(width + 500);
    mHeader += "\" height=\"";
    mHeader += QString::number(height + 500);
    mHeader += "\" xmlns=\"http://www.w3.org/2000/svg\">\n";
    mHeader += "<rect width=\"100%\" height=\"100%\" fill=\"black\" />";
    mHeader += "<rect x=\"";
    mHeader += QString::number(250);
    mHeader += "\" y=\"";
    mHeader += QString::number(250);
    mHeader += "\" width=\"";
    mHeader += QString::number(width);
    mHeader += "\" height=\"";
    mHeader += QString::number(height);
    mHeader += "\" style=\"stroke: #ffffff; stroke-width: 25; fill: none; \" />\n";
}

void SVGBuilder::insertRect(double x, double y, size_t width, size_t height, int r, int g, int b)
{
    mShapes += "<rect x=\"";
    mShapes += QString::number(x + 250);
    mShapes += "\" y=\"";
    mShapes += QString::number(y + 250);
    mShapes += "\" width=\"";
    mShapes += QString::number(width);
    mShapes += "\" height=\"";
    mShapes += QString::number(height);
    mShapes += "\" fill=\"rgb(";
    mShapes += QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + ")\" />\n";
}

std::string SVGBuilder::getSVG()
{
    QString final = mHeader + mShapes + "</svg>";
    return final.toStdString();
}