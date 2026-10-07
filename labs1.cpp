#include <iostream>

double absolute_value(double value)
{
    if (value < 0.0)
    {
        return -value;
    }
    return value;
}

double square_root(double value)
{
    if (value <= 0.0)
    {
        return 0.0;
    }
    double guess = value;
    for (int i = 0; i < 20; i++)
    {
        guess = (guess + value / guess) / 2.0;
    }
    return guess;
}

double compute_distance(double x1, double y1, double x2, double y2)
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    double dist_sq = dx * dx + dy * dy;
    return square_root(dist_sq);
}

int classify_point(double distance, double radius)
{
    const double epsilon = 1e-10;
    if (absolute_value(distance - radius) < epsilon)
    {
        return 0;
    }
    if (distance < radius)
    {
        return -1;
    }
    return 1;
}

double distance_to_circle(double distance, double radius, int classification)
{
    if (classification == 0)
    {
        return 0.0;
    }
    if (classification == -1)
    {
        return radius - distance;
    }
    return distance - radius;
}

void input_data(double& x0, double& y0, double& R, double& x, double& y)
{
    std::cout << "Enter center coordinates x0 y0: ";
    std::cin >> x0 >> y0;
    std::cout << "Enter radius R: ";
    std::cin >> R;
    std::cout << "Enter point coordinates x y: ";
    std::cin >> x >> y;
}

void output_results(double dist_to_center, double dist_to_circle, int classification)
{
    std::cout << "Distance to center: " << dist_to_center << '\n';
    if (classification == 0)
    {
        std::cout << "Point is on the circle." << '\n';
    }
    else if (classification == -1)
    {
        std::cout << "Point is inside the circle." << '\n';
    }
    else
    {
        std::cout << "Point is outside the circle." << '\n';
    }
    std::cout << "Distance to circle: " << dist_to_circle << '\n';
}

int main()
{
    double x0, y0, R, x, y;
    input_data(x0, y0, R, x, y);
    double dist_to_center = compute_distance(x0, y0, x, y);
    int classification = classify_point(dist_to_center, R);
    double dist_to_circle = distance_to_circle(dist_to_center, R, classification);
    output_results(dist_to_center, dist_to_circle, classification);
    return 0;
}
