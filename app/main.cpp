#include <Helix.h>
#include <Circle.h>
#include <Ellipse.h>

#include <omp.h>
#include <vector>
#include <memory>
#include <random>
#include <iostream>
#include <algorithm>

std::vector<std::shared_ptr<Curve>> createCurves(size_t size)
{
    std::vector<std::shared_ptr<Curve>> curves;
    curves.reserve(size);

    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_real_distribution<float> realDist(1, 10);
    std::uniform_int_distribution<int> intDist(0, 2);
    for (size_t i = 0; i < size; i++)
    {
        switch (intDist(engine))
        {
            case 0:
                curves.push_back(std::make_unique<Circle>(realDist(engine)));
                break;
            case 1:
                curves.push_back(std::make_unique<Ellipse>(realDist(engine), realDist(engine)));
                break;
            case 2:
                curves.push_back(std::make_unique<Helix>(realDist(engine), realDist(engine)));
                break;
            default:
                throw std::runtime_error("createCurves error");
        }
    }

    return curves;
}

int main()
{
    // 2. Populate a container
    std::vector<std::shared_ptr<Curve>> curves = createCurves(100);

    // 3. Print coordinates
    const float t = M_PI_4;
    for (const std::shared_ptr<Curve>& curve : curves)
    {
        Vector p = curve->getPoint(t);
        std::cout << "Point(" << p.x << ", " << p.y << ", " << p.z << ')' << std::endl;

        Vector d = curve->getDerivative(t);
        std::cout << "Derivative(" << d.x << ", " << d.y << ", " << d.z << ')' << std::endl << std::endl;
    }

    // 4. Populate a second container
    std::vector<std::shared_ptr<Circle>> circles;
    circles.reserve(curves.size());
    for (const std::shared_ptr<Curve>& curve : curves)
    {
        if (const std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(curve))
        {
            circles.push_back(circle);
        }
    }

    // 5. Sort the second container
    std::sort(circles.begin(), circles.end(), [](const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) { return a->radius < b->radius; });

    // 6, 8. Compute the total sum
    float totalRadius = 1;
    #pragma omp parallel for reduction(+:totalRadius)
    for (size_t i = 0; i < circles.size(); i++)
    {
        totalRadius += circles[i]->radius;
    }

    std::cout << totalRadius << std::endl;

}