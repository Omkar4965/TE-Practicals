search_tree = {
    "Admission": {
        "Cutoff": "The cutoff is > 99 percentile for MHTCET. For more info, refer https://pict.edu/cutoff-FE/",
        "Fee": "The fees is 93K for open-category candidates. For more info, refer https://pict.edu/fee-structure/",
        "Branch": "Branches are COMP, IT, EnTC, ECE, AIDS",
    },

    "Hostel": "The campus has a girls and boys hostel in-premises. For more info, refer https://pict.edu/hostel/",
    "Placement": {
        "Statistic": "For this year, 706 students are placed. For detailed statistics, refer https://pict.edu/placement/index.php#statistics",
        "Training": "https://pict.edu/placement/index.php#trainingactivities",
    },

    "Library": "PICT central library being information hub provides access to full text, digital and printed resources to support the scholarly and informational needs of the students, faculty, researchers, and other users.",
    "Timetable": "https://pict.edu/time_table_syllabus/",
    "Syllabus": "https://pict.edu/time_table_syllabus/",
}

def search(query, search_tree):
    query = query.lower()

    if(type(search_tree) == str):
        print("reply: ", search_tree)
        return
    
    found = False
    
    for node in search_tree:
        if node.lower() in query:
            search(query, search_tree[node])
            found = True
            break

    if not found:
        print("Query is not correct.")

while(True):
    question = input("Enter query: ")
    search(question, search_tree)
    
