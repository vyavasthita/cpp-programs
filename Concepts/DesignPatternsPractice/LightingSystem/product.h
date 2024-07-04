#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED


class AC
{
    public:
        AC();
        virtual ~AC();

        virtual const char* getName() = 0;
        virtual unsigned short getPrice() = 0;
        virtual void switchOn() = 0;
        virtual void switchOff() = 0;

    private:
        const char* m_opName;
        unsigned short m_onPrice;
};

class TataAC : public AC
{
    public:
        TataAC();
        virtual ~TataAC();

        virtual const char* getName();
        virtual unsigned short getPrice();
        virtual void switchOn();
        virtual void switchOff();

    private:
        const char* m_opName;
        unsigned short m_onPrice;
};

class HoneywellAC : public AC
{
    public:
        HoneywellAC();
        virtual ~HoneywellAC();

        virtual const char* getName();
        virtual unsigned short getPrice();
        virtual void switchOn();
        virtual void switchOff();

    private:
        const char* m_opName;
        unsigned short m_onPrice;
};

// TubeLight
class TubeLight
{
    public:
        TubeLight();
        virtual ~TubeLight();

        virtual const char* getName() = 0;
        virtual unsigned short getPrice() = 0;
        virtual void switchOn() = 0;
        virtual void switchOff() = 0;

    private:
        const char* m_opName;
        unsigned short m_onPrice;
};

class TataTubeLight : public TubeLight
{
    public:
        TataTubeLight();
        virtual ~TataTubeLight();

        virtual const char* getName();
        virtual unsigned short getPrice();
        virtual void switchOn();
        virtual void switchOff();

    private:
        const char* m_opName;
        unsigned short m_onPrice;
};

class HoneywellTubeLight : public TubeLight
{
    public:
        HoneywellTubeLight();
        virtual ~HoneywellTubeLight();

        virtual const char* getName();
        virtual unsigned short getPrice();
        virtual void switchOn();
        virtual void switchOff();

    private:
        const char* m_opName;
        unsigned short m_onPrice;
};


#endif // PRODUCT_H_INCLUDED
