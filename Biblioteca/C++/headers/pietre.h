    public:
        class pietra{
            private:
                std::string tipoPietra;
                int caratura;
                std::string taglio;
                double valorePietra;
            public:
                pietra(std::string np, int car, std::string ta) : 
                tipoPietra(np), caratura(car), taglio(ta){};
                ~pietra(){};

                //getter
                std::string getTPietra()const{return tipoPietra;}
                int getCaratura()const{return caratura;}
                std::string getTaglio()const{return taglio;}
                double getValPietra()const{return valorePietra;}
                //setter
                void setNPietra(std::string pie){tipoPietra = pie;}
                void setCaratura(int c){caratura = c;}
                void setTaglio(std::string t){taglio = t;}
                void setValPietra(double vp) {valorePietra = vp;}
    };