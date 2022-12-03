#include "ConcatStringTree.cpp" // input your ConcatStringTree.cpp directory, you only need this file

using namespace std;

const string dir_inp = "C:\\Users\\Bao\\source\\repos\\Assignment2DSA\\Assignment2DSA\\input\\";
const string dir_out = "C:\\Users\\Bao\\source\\repos\\Assignment2DSA\\Assignment2DSA\\output\\";
const string dir_inp2 = "C:\\Users\\Bao\\source\\repos\\Assignment2DSA\\Assignment2DSA\\inputReduced\\";
const string dir_out2 = "C:\\Users\\Bao\\source\\repos\\Assignment2DSA\\Assignment2DSA\\outputReduced\\";
// input the directory where the ConcatStringTree_testcases folder located, use \\ for 

// --- NO NEED TO INCLUDE OTHER LIBRARY ---
void readTestcase(int test) {
    fstream inp(dir_inp + "test" + to_string(test) + ".txt", ios::in);
    fstream out(dir_out + "test" + to_string(test) + ".txt", ios::in);
    if (!inp.is_open())
        return;
    string line, exp_res;
    vector<ConcatStringTree*> CSTVector(300000, nullptr);
    vector<string> exp_answer, act_answer;
    while (getline(out, exp_res))
    {
        exp_answer.push_back(exp_res);
    }
    while (getline(inp, line))
    {
        string act_res = "";
        int index = line.find(" - ");
        if (index != string::npos)
        {
            string id = line.substr(0, index);
            string instruction = line.substr(index + 3);
            int ID = stoi(id.substr(3));
            if (instruction == "toString")
            {
                act_res = CSTVector[ID]->toString();
            }
            else if (instruction == "toStringPreOrder")
            {
                act_res = CSTVector[ID]->toStringPreOrder();
            }
            else if (instruction == "length")
            {
                act_res = to_string(CSTVector[ID]->length());
            }
            else if (instruction == "delete")
            {
                try
                {
                    if (CSTVector[ID] == nullptr)
                    {
                        act_res = "Don't need to delete object " + to_string(ID);
                    }
                    else
                    {
                        delete CSTVector[ID];
                        act_res = "Object " + to_string(ID) + " has been deleted!";
                        CSTVector[ID] = nullptr;
                    }
                }
                catch (exception& e)
                {
                    act_res = e.what();
                }
                //cout << ID << endl;
            }
            else if (instruction.find("getParTreeSize ") != string::npos)
            {
                string query;
                if (instruction.length() == 15)
                {
                    query = "";
                }
                else
                {
                    query = instruction.substr(16);
                }
                try
                {
                    act_res = to_string(CSTVector[ID]->getParTreeSize(query));
                }
                catch (exception& e)
                {
                    act_res = e.what();
                }
            }
            else if (instruction.find("getParTreeStringPreOrder ") != string::npos)
            {
                string query;
                if (instruction.length() == 25)
                {
                    query = "";
                }
                else
                {
                    query = instruction.substr(26);
                }
                try
                {
                    act_res = CSTVector[ID]->getParTreeStringPreOrder(query);
                }
                catch (exception& e)
                {
                    act_res = e.what();
                }
            }
            else
            {
                int space_idx = instruction.find(' ');
                string key = instruction.substr(0, space_idx);
                if (key == "init")
                {
                    string variable = instruction.substr(space_idx + 1);
                    try
                    {
                        CSTVector[ID] = new ConcatStringTree(variable.c_str());
                        act_res = "Success";
                    }
                    catch (exception& e)
                    {
                        act_res = e.what();
                    }
                }
                else if (key == "get")
                {
                    int idx = stoi(instruction.substr(space_idx + 1));
                    try
                    {
                        act_res += CSTVector[ID]->get(idx);
                    }
                    catch (exception& e)
                    {
                        act_res = e.what();
                    }
                }
                else if (key == "indexOf")
                {
                    char c = instruction[(int)instruction.length() - 1];
                    act_res = to_string(CSTVector[ID]->indexOf(c));
                }
                else
                {
                    act_res = "Invalid instruction: " + line;
                }
            }
        }
        else
        {
            index = line.find(": ");
            if (index != string::npos)
            {
                string instruction = line.substr(0, index);
                string code = line.substr(index + 2);
                if (instruction == "concat")
                {
                    int index, a, b;
                    stringstream ss(code);
                    ss >> index >> a >> b;
                    try
                    {
                        CSTVector[index] = new ConcatStringTree(CSTVector[a]->concat(*CSTVector[b]));
                        act_res = "Success";
                    }
                    catch (exception& e)
                    {
                        act_res = e.what();
                    }
                }
                else if (instruction == "reverse")
                {
                    int index, a;
                    stringstream ss(code);
                    ss >> index >> a;
                    try
                    {
                        CSTVector[index] = new ConcatStringTree(CSTVector[a]->reverse());
                        act_res = "Success";
                    }
                    catch (exception& e)
                    {
                        act_res = e.what();
                    }
                }
                else if (instruction == "subString")
                {
                    int index1, index2, from, to;
                    stringstream ss(code);
                    ss >> index1 >> index2 >> from >> to;
                    try
                    {
                        CSTVector[index1] = new ConcatStringTree(CSTVector[index2]->subString(from, to));
                        act_res = "Success";
                    }
                    catch (exception& e)
                    {
                        act_res = e.what();
                    }
                }
                else
                {
                    act_res = "Invalid instruction: " + line;
                }
            }
            else
            {
                act_res = "Invalid instruction: " + line;
            }
        }
        act_answer.push_back(act_res);
    }
    if (act_answer == exp_answer)
    {
        cout << "Testcase " << test << " correct!\n";
    }
    else
    {
        if (act_answer.size() > exp_answer.size())
        {
            cout << "Did you add some redundant lines?\n";
            //abort();
        }
        else if (act_answer.size() < exp_answer.size())
        {
            cout << "Did you miss something?\n";
            //abort();
        }
        for (int i = 0; i < (int)min(act_answer.size(), exp_answer.size()); i++)
        {
            if (act_answer[i] != exp_answer[i])
            {
                cout << "Expected " << exp_answer[i] << ", got " << act_answer[i] << '\n';
                //abort();
            }
        }
    }
}

void readTestcaseReduced(int test, int& count)
{
    fstream inp(dir_inp2 + "testReduced" + to_string(test) + ".txt", ios::in);
    fstream out(dir_out2 + "testReduced" + to_string(test) + ".txt", ios::in);
    vector<string> exp_answer, act_answer;
    string line, exp_res;
    while (getline(out, exp_res))
    {
        exp_answer.push_back(exp_res);
    }
    vector<ReducedConcatStringTree*> RCSTVector(300000, nullptr);
    LitStringHash* litStringHash = nullptr;
    HashConfig hashConfig;
    while (getline(inp, line))
    {
        string act_res;
        int index = line.find(" - ");
        if (index != string::npos)
        {
            string id = line.substr(0, index);
            string instruction = line.substr(index + 3);
            if (id == "litStringHash")
            {
                if (instruction == "toString")
                {
                    if (litStringHash != nullptr)
                    {
                        getline(out, exp_res);
                        act_res = litStringHash->toString();
                        act_answer.push_back(act_res);
                    }
                }
                else if (instruction == "getLastInsertedIndex")
                {
                    if (litStringHash != nullptr)
                    {
                        getline(out, exp_res);
                        act_res = to_string(litStringHash->getLastInsertedIndex());
                        act_answer.push_back(act_res);
                    }
                    //cout << id << endl;
                }
                else if (instruction == "delete")
                {
                    if (litStringHash != nullptr)
                    {
                        getline(out, exp_res);
                        act_res = "litStringHash has been deleted!";
                        act_answer.push_back(act_res);
                        delete litStringHash;
                    }
                }
                else
                {
                    cout << "Invalid instruction: " << line << '\n';
                    return;
                }
            }
            else
            {
                int ID = stoi(id.substr(4));
                if (instruction == "toString")
                {
                    getline(out, exp_res);
                    act_res = RCSTVector[ID]->toString();
                    act_answer.push_back(act_res);
                }
                else if (instruction == "toStringPreOrder")
                {
                    getline(out, exp_res);
                    act_res = RCSTVector[ID]->toStringPreOrder();
                    act_answer.push_back(act_res);
                }
                else if (instruction == "length")
                {
                    getline(out, exp_res);
                    act_res = to_string(RCSTVector[ID]->length());
                    act_answer.push_back(act_res);
                }
                else if (instruction == "delete")
                {
                    getline(out, exp_res);
                    try
                    {
                        if (RCSTVector[ID] == nullptr)
                        {
                            act_res = "Don't need to delete object " + to_string(ID);
                        }
                        else
                        {
                            delete RCSTVector[ID];
                            act_res = "Object " + to_string(ID) + " has been deleted!";
                            RCSTVector[ID] = nullptr;
                        }
                    }
                    catch (exception& e)
                    {
                        act_res = e.what();
                    }
                    act_answer.push_back(act_res);
                }
                else if (instruction.find("getParTreeSize ") != string::npos)
                {
                    string query;
                    getline(out, exp_res);
                    if (instruction.length() == 15)
                    {
                        query = "";
                    }
                    else
                    {
                        query = instruction.substr(16);
                    }
                    try
                    {
                        act_res = to_string(RCSTVector[ID]->getParTreeSize(query));
                    }
                    catch (exception& e)
                    {
                        act_res = e.what();
                    }
                    act_answer.push_back(act_res);
                }
                else if (instruction.find("getParTreeStringPreOrder ") != string::npos)
                {
                    string query;
                    getline(out, exp_res);
                    if (instruction.length() == 25)
                    {
                        query = "";
                    }
                    else
                    {
                        query = instruction.substr(26);
                    }
                    try
                    {
                        act_res = RCSTVector[ID]->getParTreeStringPreOrder(query);
                    }
                    catch (exception& e)
                    {
                        act_res = e.what();
                    }
                    act_answer.push_back(act_res);
                }
                else
                {
                    int space_idx = instruction.find(' ');
                    string key = instruction.substr(0, space_idx);
                    if (key == "init")
                    {
                        getline(out, exp_res);
                        string variable = instruction.substr(space_idx + 1);
                        try
                        {
                            RCSTVector[ID] = new ReducedConcatStringTree(variable.c_str(), litStringHash);
                            act_res = "Success";
                        }
                        catch (exception& e)
                        {
                            act_res = e.what();
                        }
                        act_answer.push_back(act_res);
                    }
                    else if (key == "get")
                    {
                        getline(out, exp_res);
                        int idx = stoi(instruction.substr(space_idx + 1));
                        try
                        {
                            act_res = RCSTVector[ID]->get(idx);
                        }
                        catch (exception& e)
                        {
                            act_res = e.what();
                        }
                        act_answer.push_back(act_res);
                    }
                    else if (key == "indexOf")
                    {
                        getline(out, exp_res);
                        char c = instruction[(int)instruction.length() - 1];
                        act_res = to_string(RCSTVector[ID]->indexOf(c));
                        act_answer.push_back(act_res);
                    }
                    else
                    {
                        cout << "Invalid instruction: " << line << '\n';
                        return;
                    }
                }
            }
        }
        else
        {
            index = line.find(": ");
            if (index != string::npos)
            {
                string instruction = line.substr(0, index);
                string code = line.substr(index + 2);
                if (instruction == "HashConfig")
                {
                    stringstream ss(code);
                    int p, initSize;
                    double c1, c2, lambda, alpha;
                    ss >> p >> c1 >> c2 >> lambda >> alpha >> initSize;
                    hashConfig = HashConfig(p, c1, c2, lambda, alpha, initSize);
                }
                else if (instruction == "concat")
                {
                    int index, a, b;
                    stringstream ss(code);
                    ss >> index >> a >> b;
                    getline(out, exp_res);
                    try
                    {
                        RCSTVector[index] = new ReducedConcatStringTree(RCSTVector[a]->concat(*RCSTVector[b]));
                        act_res = "Success";
                    }
                    catch (exception& e)
                    {
                        act_res = e.what();
                    }
                    act_answer.push_back(act_res);
                }
                else
                {
                    cout << "Invalid instruction: " << line << '\n';
                    return;
                }
            }
            else
            {
                if (line == "init litStringHash")
                {
                    litStringHash = new LitStringHash(hashConfig);
                }
                else
                {
                    cout << "Invalid instruction: " << line << '\n';
                    return;
                }
            }
        }
    }
    if (act_answer == exp_answer) {
        count++;
        cout << "Testcase " << test << " correct!\n";
    }
    else {
        if (act_answer.size() > exp_answer.size()) {
            cout << "Did you add some redundant lines?\n";
            //abort();
        }
        else if (act_answer.size() < exp_answer.size()) {
            cout << "Did you miss something?\n";
            //abort();
        }
        for (int i = 0; i < (int)min(act_answer.size(), exp_answer.size()); i++)
        {
            if (act_answer[i] != exp_answer[i])
            {
                cout << "Expected " << exp_answer[i] << ", got " << act_answer[i] << '\n';
                cout << i << endl;
                //abort();
            }
        }
    }
}

int main(int argc, char** argv) {
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    cout << "Check ConcatStringTree:\n";
    for (int i = 1; i <= 100; i++) {
        key = 1;
        readTestcase(i);
    }

    cout << "Check ReducedConcatStringTree:\n";
    int count = 0;
    for(int i = 1; i <= 100; i++){
        key = 1;
        readTestcaseReduced(i, count);
    }
    cout << count;
    return 0;
}