#pragma once
class IProductor {
public:
    virtual ~IProductor() = default;
    virtual double producirEnergia() = 0;
};
