#pragma once
const int SUBJECT_NAME_LENGTH = 30;

const int STUDENT_NAME_LENGTH = 30;

const int GROUP_NAME_LENGTH = 10;
struct subject {
    char name[SUBJECT_NAME_LENGTH];
    int grade;
};

struct Student {
    char surname[STUDENT_NAME_LENGTH];
    char name[STUDENT_NAME_LENGTH];
    char group[GROUP_NAME_LENGTH];
    subject math;
    subject physics;
    subject english;
    subject ukrainian;
};