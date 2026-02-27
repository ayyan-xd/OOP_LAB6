    #include <iostream>
    using namespace std;

    class HospitalStaff {
    protected :
    int staffID;
    string name;
    public :
    HospitalStaff(int id, string n) : staffID(id), name(n) {}
    void getRole() {
        cout << "Hospital Staff" << endl;
        }
    };

    class Dotor : public HospitalStaff {
    private :
    string specialization;
    public :
    Dotor(int id, string n, string s) : HospitalStaff(id, n), specialization(s) {}
    void getRole() {
        cout << "Doctor" << endl;
        }
        void prescribe(string patientName) {
            cout << "Dr. " << name << " prescribes medication to " << patientName << endl;
        }
    };

    class Nruse : public HospitalStaff {
    private :
        string ward;
    public :
    Nruse(int id, string n, string w) : HospitalStaff(id, n), ward(w) {}
    void getRole() {
        cout << "Nurse" << endl;
        }
        void assist(string doctorName) {
            cout << name << " assists Dr. " << doctorName << endl;
        }
    };

    class administrstor : protected HospitalStaff {
    private :
    string officeLoation;
    public :
    administrstor(int id, string n, string o) : HospitalStaff(id, n), officeLoation(o) {}
    void scheduleAppointment(string patientName) {
        cout << name << " schedules an appointment for " << patientName << " in " << officeLoation << endl;
        }
    };

    int main() {
    Dotor doc1(101, "Smith", "Cardiology");
    Nruse nurse1(201, "Johnson", "Ward A");
    administrstor admin1(301, "Brown", "Office 1");
    doc1.getRole();
    doc1.prescribe("Alice");
    nurse1.getRole();
    nurse1.assist("Smith");
    admin1.scheduleAppointment("Bob"); 
    /* we can't call getRole() for admin1 because it inherits HospitalStaff as protective making all 
    it's members inaccessible outside the administrstor class. So, it is inaccessible in main function.*/
    return 0;
    }
