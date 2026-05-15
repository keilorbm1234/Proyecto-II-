#pragma once
class IConsumidor {
public:
    virtual ~IConsumidor() = default;
    virtual double consumirEnergia() = 0;
};
