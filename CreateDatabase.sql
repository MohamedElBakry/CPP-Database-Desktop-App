/* Uncomment if needed */
CREATE DATABASE lhu_db;

USE lhu_db;

CREATE TABLE Students (
    studentID INT AUTO_INCREMENT PRIMARY KEY,
    forename VARCHAR(35) NOT NULL,
    surname VARCHAR(35) NOT NULL,
    dateOfBirth DATE NOT NULL,
    studyLevel CHAR(1) NOT NULL,
    resProjName VARCHAR(100)
);

CREATE TABLE degreePrograms (
    degreeID INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(70) NOT NULL,
    startDate DATE,
    endDate DATE
);

CREATE TABLE Courses (
    courseID INT AUTO_INCREMENT PRIMARY KEY,
    degreeID INT NOT NULL,
    name VARCHAR(40) NOT NULL,
    courseLevel CHAR(1),

    FOREIGN KEY (degreeID) REFERENCES degreePrograms(degreeID) ON UPDATE CASCADE ON DELETE RESTRICT
);

CREATE TABLE Assessments (
    assessmentID INT AUTO_INCREMENT PRIMARY KEY,
    courseID INT NOT NULL,
    name VARCHAR(40) NOT NULL,
    weighting INT NOT NULL,
    deadline DATE NOT NULL,

    FOREIGN KEY (courseID) REFERENCES Courses(courseID) ON UPDATE CASCADE ON DELETE RESTRICT
);

CREATE TABLE studentsDegrees (
    studentID INT NOT NULL,
    degreeID INT NOT NULL,
    overallGrade VARCHAR(3),

    FOREIGN KEY (studentID) REFERENCES Students(studentID) ON UPDATE CASCADE ON DELETE RESTRICT,
    FOREIGN KEY (degreeID) REFERENCES degreePrograms(degreeID) ON UPDATE CASCADE ON DELETE RESTRICT
);

CREATE TABLE studentsCourses (
    studentID INT NOT NULL,
    courseID INT NOT NULL,
    mark INT,
    letterGrade VARCHAR(3), /* We will run a trigger on insertion or call a conversion function */
    progressionCode VARCHAR(150),

    FOREIGN KEY (studentID) REFERENCES Students(studentID) ON UPDATE CASCADE ON DELETE RESTRICT,
    FOREIGN KEY (courseID) REFERENCES Courses(courseID) ON UPDATE CASCADE ON DELETE RESTRICT
);

CREATE TABLE studentsAssessments (
    studentID INT NOT NULL,
    assessmentID INT NOT NULL,
    mark INT NOT NULL,
    letterGrade VARCHAR(3) NOT NULL,
    concessionalCode CHAR(2),

    FOREIGN KEY (studentID) REFERENCES Students(studentID) ON UPDATE CASCADE ON DELETE RESTRICT,
    FOREIGN KEY (assessmentID) REFERENCES Assessments(assessmentID) ON UPDATE CASCADE ON DELETE RESTRICT
);

-- Functions
DROP FUNCTION IF EXISTS I_SID;

DELIMITER $$
CREATE FUNCTION I_SID (fn VARCHAR(35)) 
RETURNS INT
DETERMINISTIC
BEGIN 
  DECLARE sID INT;
  SELECT studentID INTO sID FROM students where forename = fn;
  RETURN sID;
END$$
DELIMITER ;
