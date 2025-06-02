# Hospital Management System 🏥

A C++ based hospital management system that handles various medical services and procedures.

## Features

- Manage different types of medical services:
  - Consultations
  - Emergency care
  - Surgeries
  - Laboratory tests
  - Radiology services
- Add new medical services
- Remove existing services
- View detailed service information

## System Architecture

### Base Class: `Prestation`
```cpp
class Prestation {
    string nom;          // Service name
    string departement;  // Department
    int code;           // Unique identifier
};
```

### Service Types
1. **Consultation**
   - Doctor name
   - Specialty

2. **Emergency**
   - Emergency type
   - Administered medications

3. **Surgery**
   - Surgeon name
   - Operating room number

4. **Laboratory Test**
   - Blood quantity
   - Test type

5. **Radiology**
   - Radiation dosage
   - Scan type

### Hospital Management
The `Hopital` class manages all services with methods for:
- Adding services
- Removing services
- Displaying service information

## Implementation

The main program demonstrates:
1. Hospital instance creation
2. Adding various medical services
3. Service removal by ID
4. Complete service listing

## Getting Started

1. Clone the repository
2. Compile the C++ source files
3. Run the executable

## Requirements
- C++ compiler with C++11 support
- Standard Template Library (STL)
