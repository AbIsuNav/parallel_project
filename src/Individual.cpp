//
// Created by sliberman on 4/5/19.
//

#include "utils.h"
#include "Individual.h"

Individual::Individual(int number_of_polygons, int number_of_vertices, int max_x, int max_y,
                       list<Polygon *> *cloned_polys) {
    this->max_x = max_x;
    this->max_y = max_y;
    this->dna = cloned_polys;
}


Individual::Individual(int number_of_polygons, int number_of_vertices, int max_x, int max_y) {
    this->max_x = max_x;
    this->max_y = max_y;
    for (int i = 0; i < number_of_polygons; ++i) {
        this->dna->push_back(Polygon::random_polygon(number_of_polygons, max_x, max_y));
    }
}

void Individual::mutate() {
    list<Polygon *> *dna = this->dna;
    int len = dna->size();

    int idx1 = utils::nextInt(len - 1);
    Polygon *poly = this->dna->at(idx1);
    double r = utils::random();

    if (r < 0.45) {
        Colour *colour = poly->colour;
        if (r < 0.1125) {
            colour->set_r(Colour::random_colour());
        } else if (r < 0.2250) {
            colour->set_g(Colour::random_colour());
        } else if (r < 0.3375) {
            colour->set_b(Colour::random_colour());
        } else {
            colour->set_a(1 - utils::random());
        }
    } else if (r < 0.9) {
        if (r < 0.675) {
            poly->move(this->max_x, this->max_y);
        } else {
            Point *point = poly->get_point(utils::nextInt(poly->get_points_length()));
            if (r < 0.7875) {
                point->set_x(utils::nextInt(this->max_x));
            } else {
                point->set_y(utils::nextInt(this->max_y))
            }
        }
    } else if (r < 0.95) {
        if (r < 0.925) {
            poly->remove_point();
        } else {
            int len2 = poly->get_points_length();
            poly->insert_point(utils::nextInt(len2),
                    new Point(utils::nextInt(this->max_x), utils::nextInt(this->max_y)));
        }
    } else {
        if (r < 0.975) {
            if (len >= 2) {
            }
        }
    }
}

Polygon *Individual::get_dna(int index) {
    auto it = next(this->dna, index);
    return it;
}
