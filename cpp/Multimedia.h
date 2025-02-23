#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>

class Multimedia {
    private:
        std::string name;
        std::string filename;


    protected:
        //Pour verifier si le nom et le l'emplacement de fichier sont valides
        static bool isValid(const std::string& s, bool allowDot = false) {
            for (char c : s) {
                if (std::isalnum(static_cast<unsigned char>(c)) || c == '_' || c == '-' || c == '/') {
                    continue;
                }
                if (allowDot && c == '.') {
                    continue;
                }
                return false;
            }
            return true;
        }

    public:
        Multimedia(std::string name = "", std::string filename = "");

        virtual std::string classname() const;

        virtual ~Multimedia();

        void setName(std::string name);
        void setFilename(std::string filename);

        std::string getName() const;
        void getName(std::ostream& os) const;
        std::string getFilename() const;

        virtual void display(std::ostream& os) const;
        virtual void write(std::ostream& os) const;
        virtual void read(std::istream& is);

        virtual void play() const = 0;
};

#endif