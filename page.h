#ifndef PAGE_H
#define PAGE_H

class Page
{
public:
    void virtual initializePage() = 0;
    void virtual setState(bool isActive) = 0;
};

#endif // PAGE_H
