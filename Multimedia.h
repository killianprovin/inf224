#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>

class Multimedia {
    private:
        std::string name;
        std::string filename;

    public:
        Multimedia(std::string name, std::string filename);
        Multimedia();

        ~Multimedia();

        void setName(std::string name);
        void setFilename(std::string filename);

        std::string getName() const;
        std::string getFilename() const;

        virtual void display(std::ostream& os) const;
};

#endif