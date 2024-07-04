#ifndef PRODUCTFACTORY_H_INCLUDED
#define PRODUCTFACTORY_H_INCLUDED


class ProductFactory
{
    public:
        ProductFactory();
        virtual ~ProductFactory();

        virtual AC* createAC() = 0;
        virtual TubeLight* createTubelight() = 0;

    private:
        AC* m_opAC;
        TubeLight* m_opTubeLight;
};

class TataProductFactory : public ProductFactory
{
    public:
        TataProductFactory();
        virtual ~TataProductFactory();

        virtual AC* createAC();
        virtual TubeLight* createTubelight();

    private:
        AC* m_opAC;
        TubeLight* m_opTubeLight;
};

class HoneywellProductFactory : public ProductFactory
{
    public:
        HoneywellProductFactory();
        virtual ~HoneywellProductFactory();

        virtual AC* createAC();
        virtual TubeLight* createTubelight();

    private:
        AC* m_opAC;
        TubeLight* m_opTubeLight;
};

#endif // PRODUCTFACTORY_H_INCLUDED
