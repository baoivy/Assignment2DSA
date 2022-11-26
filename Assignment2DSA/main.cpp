#include "ConcatStringTree.h"

void tc1()
{
    ConcatStringTree s1("acbbcab");
    cout << s1.length() << endl;
    cout << s1.get(1) << endl;
    try {
        cout << "char at index 10: " << s1.get(10) << endl;
    }
    catch (const out_of_range& ofr) {
        cout << "Exception out_of_range: " << ofr.what() << endl;
    }
    cout << s1.indexOf('b') << endl;

    /* Expected:
    7
    c
    char at index 10: Exception out_of_range: Index of string is invalid!
    2
    */
}

void tc2()
{
    ConcatStringTree s1("Hello");
    ConcatStringTree s2(",_t");
    ConcatStringTree s3 = s1.concat(s2);
    cout << s3.toStringPreOrder() << endl;
    cout << s3.toString() << endl;
    cout << s3.subString(5, 6).toString() << endl;
    cout << s3.reverse().toString() << endl;

    /* Expected:
    ConcatStringTree[(LL=5,L=8,<NULL>);(LL=0,L=5,"Hello");(LL=0,L=3,",_t")]
    ConcatStringTree["Hello,_t"]
    ConcatStringTree[","]
    ConcatStringTree["t_,olleH"]
    */
}

void tc3()
{
    ConcatStringTree* s1 = new ConcatStringTree("a");
    ConcatStringTree* s2 = new ConcatStringTree("b");
    ConcatStringTree* s3 = new ConcatStringTree(s1->concat(*s2));
    ConcatStringTree* s4 = new ConcatStringTree("c");
    ConcatStringTree* s5 = new ConcatStringTree("d");
    ConcatStringTree* s6 = new ConcatStringTree(s4->concat(*s5));
    ConcatStringTree* s7 = new ConcatStringTree(s3->concat(*s6));
    ConcatStringTree* s8 = new ConcatStringTree(s1->concat(*s4));
    /*ConcatStringTree* s9 = new ConcatStringTree(s1->concat(*s3));
    ConcatStringTree* s10 = new ConcatStringTree("e");
    ConcatStringTree* s11 = new ConcatStringTree("f");
    ConcatStringTree* s12 = new ConcatStringTree(s10->concat(*s11));
    ConcatStringTree* s13 = new ConcatStringTree("g");
    ConcatStringTree* s14 = new ConcatStringTree("h");
    ConcatStringTree* s15 = new ConcatStringTree(s13->concat(*s14));
    ConcatStringTree* s16 = new ConcatStringTree(s12->concat(*s15));
    ConcatStringTree* s17 = new ConcatStringTree(s7->concat(*s16));
    ConcatStringTree* s18 = new ConcatStringTree(s1->concat(*s13));*/

    cout << s1->getParTreeSize("") << endl;
    cout << s1->getParTreeStringPreOrder("") << endl;

    delete s3;
    delete s2;
    delete s1;
    delete s6;
    delete s5;
    delete s4;
    delete s7;
    delete s8;
    /*delete s17;
    delete s16;
    delete s13;
    delete s14;
    delete s12;
    delete s11;
    delete s9;
    delete s10;
    delete s18;
    delete s15;*/

    /* Expected:
    2
    ParentsTree[(id=1);(id=3)]
    */
}

void tc4()
{
    HashConfig hashConfig(2, 0.5, 0.5, 0.75, 2, 4);
    LitStringHash* litStringHash = new LitStringHash(hashConfig);
    ReducedConcatStringTree* s1 = new ReducedConcatStringTree("a", litStringHash);
    ReducedConcatStringTree* s2 = new ReducedConcatStringTree("bb", litStringHash);

    cout << s1->toString() << endl;
    cout << s2->toString() << endl;
    ReducedConcatStringTree* s3 = new ReducedConcatStringTree("bb", litStringHash);
    ReducedConcatStringTree* s4 = new ReducedConcatStringTree(s1->concat(*s2));

    cout << s4->toString() << endl;
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    delete s4;
    delete s3;
    delete s1;
    delete s2;
    delete litStringHash;
    /* Expected:
    ConcatStringTree["a"]
    ConcatStringTree["bb"]
    2
    LitStringHash[();(litS="a");(litS="bb");()]
    */
}

void tc5()
{
    ConcatStringTree s1("Hello");
    cout << "Please focus to id: " << s1.getParTreeStringPreOrder("") << endl;
    ConcatStringTree s2("an-nyeong-ha-se-yo");
    cout << "Please focus to id: " << s2.getParTreeStringPreOrder("") << endl;
    ConcatStringTree s3("nee how");
    cout << "Please focus to id: " << s3.getParTreeStringPreOrder("") << endl;

    /* Expected:
    Please focus to id: ParentsTree[(id=1)]
    Please focus to id: ParentsTree[(id=2)]
    Please focus to id: ParentsTree[(id=3)]
    */
}

void test()
{
    ConcatStringTree* s0 = new ConcatStringTree("0123456789");
    ConcatStringTree* s1 = new ConcatStringTree("0123456789");
    ConcatStringTree* s2 = new ConcatStringTree("0123456789");
    ConcatStringTree* s3 = new ConcatStringTree("0123456789");
    ConcatStringTree* s4 = new ConcatStringTree("0123456789");
    ConcatStringTree* s5 = new ConcatStringTree("0123456789");
    ConcatStringTree* s6 = new ConcatStringTree("0123456789");
    ConcatStringTree* s7 = new ConcatStringTree("0123456789");

    ConcatStringTree* s8 = new ConcatStringTree(s0->concat(*s1));
    ConcatStringTree* s9 = new ConcatStringTree(s1->concat(*s2));
    ConcatStringTree* s10 = new ConcatStringTree(s2->concat(*s3));
    ConcatStringTree* s11 = new ConcatStringTree(s3->concat(*s4));
    ConcatStringTree* s12 = new ConcatStringTree(s4->concat(*s5));
    ConcatStringTree* s13 = new ConcatStringTree(s5->concat(*s6));
    ConcatStringTree* s14 = new ConcatStringTree(s6->concat(*s7));

    ConcatStringTree* s15 = new ConcatStringTree(s8->concat(*s9));
    ConcatStringTree* s16 = new ConcatStringTree(s9->concat(*s10));
    ConcatStringTree* s17 = new ConcatStringTree(s10->concat(*s11));
    ConcatStringTree* s18 = new ConcatStringTree(s11->concat(*s12));
    ConcatStringTree* s19 = new ConcatStringTree(s12->concat(*s13));
    ConcatStringTree* s20 = new ConcatStringTree(s13->concat(*s14));

    ConcatStringTree* s21 = new ConcatStringTree(s15->concat(*s16));
    ConcatStringTree* s22 = new ConcatStringTree(s16->concat(*s17));
    ConcatStringTree* s23 = new ConcatStringTree(s17->concat(*s18));
    ConcatStringTree* s24 = new ConcatStringTree(s18->concat(*s19));
    ConcatStringTree* s25 = new ConcatStringTree(s19->concat(*s20));

    ConcatStringTree* s26 = new ConcatStringTree(s21->concat(*s22));
    ConcatStringTree* s27 = new ConcatStringTree(s22->concat(*s23));
    ConcatStringTree* s28 = new ConcatStringTree(s23->concat(*s24));
    ConcatStringTree* s29 = new ConcatStringTree(s24->concat(*s25));

    ConcatStringTree* s30 = new ConcatStringTree(s26->concat(*s27));
    ConcatStringTree* s31 = new ConcatStringTree(s27->concat(*s28));
    ConcatStringTree* s32 = new ConcatStringTree(s28->concat(*s29));

    ConcatStringTree* s33 = new ConcatStringTree(s30->concat(*s31));
    ConcatStringTree* s34 = new ConcatStringTree(s31->concat(*s32));

    ConcatStringTree* s35 = new ConcatStringTree(s33->concat(*s34));

    cout << "==================== BEFORE DELETE ====================" << '\n';
    cout << "PreOrder of Parent s0: " << s0->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s1: " << s1->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s2: " << s2->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s3: " << s3->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s4: " << s4->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s5: " << s5->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s6: " << s6->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s7: " << s7->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s8: " << s8->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s9: " << s9->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s10: " << s10->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s11: " << s11->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s12: " << s12->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s13: " << s13->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s14: " << s14->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s15: " << s15->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s16: " << s16->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s17: " << s17->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s18: " << s18->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s19: " << s19->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s20: " << s20->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s21: " << s21->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s22: " << s22->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s23: " << s23->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s24: " << s24->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s25: " << s25->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s26: " << s26->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s27: " << s27->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s28: " << s28->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s29: " << s29->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s30: " << s30->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s31: " << s31->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s32: " << s32->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s33: " << s33->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s34: " << s34->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s35: " << s35->getParTreeStringPreOrder("") << '\n';
    cout << "==================== END ====================" << '\n';

    delete s4;
    delete s5;
    delete s7;
    delete s9;
    delete s13;
    delete s17;
    delete s18;
    delete s21;
    delete s24;
    delete s33;
    delete s34;

    cout << "==================== CALLING s29 ====================" << '\n';
    cout << "Length of s29: " << s29->length() << '\n';
    cout << "String of s29: " << s29->toString() << '\n';
    cout << "PreOrder of s29: " << s29->toStringPreOrder() << '\n';
    cout << "Size of Parent s29: " << s29->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s29: " << s29->getParTreeStringPreOrder("") << '\n';
    delete s29;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s32 ====================" << '\n';
    cout << "Length of s32: " << s32->length() << '\n';
    cout << "String of s32: " << s32->toString() << '\n';
    cout << "PreOrder of s32: " << s32->toStringPreOrder() << '\n';
    cout << "Size of Parent s32: " << s32->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s32: " << s32->getParTreeStringPreOrder("") << '\n';
    delete s32;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s3 ====================" << '\n';
    cout << "Length of s3: " << s3->length() << '\n';
    cout << "String of s3: " << s3->toString() << '\n';
    cout << "PreOrder of s3: " << s3->toStringPreOrder() << '\n';
    cout << "Size of Parent s3: " << s3->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s3: " << s3->getParTreeStringPreOrder("") << '\n';
    delete s3;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s8 ====================" << '\n';
    cout << "Length of s8: " << s8->length() << '\n';
    cout << "String of s8: " << s8->toString() << '\n';
    cout << "PreOrder of s8: " << s8->toStringPreOrder() << '\n';
    cout << "Size of Parent s8: " << s8->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s8: " << s8->getParTreeStringPreOrder("") << '\n';
    delete s8;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s2 ====================" << '\n';
    cout << "Length of s2: " << s2->length() << '\n';
    cout << "String of s2: " << s2->toString() << '\n';
    cout << "PreOrder of s2: " << s2->toStringPreOrder() << '\n';
    cout << "Size of Parent s2: " << s2->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s2: " << s2->getParTreeStringPreOrder("") << '\n';
    delete s2;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s11 ====================" << '\n';
    cout << "Length of s11: " << s11->length() << '\n';
    cout << "String of s11: " << s11->toString() << '\n';
    cout << "PreOrder of s11: " << s11->toStringPreOrder() << '\n';
    cout << "Size of Parent s11: " << s11->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s11: " << s11->getParTreeStringPreOrder("") << '\n';
    delete s11;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s12 ====================" << '\n';
    cout << "Length of s12: " << s12->length() << '\n';
    cout << "String of s12: " << s12->toString() << '\n';
    cout << "PreOrder of s12: " << s12->toStringPreOrder() << '\n';
    cout << "Size of Parent s12: " << s12->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s12: " << s12->getParTreeStringPreOrder("") << '\n';
    delete s12;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s35 ====================" << '\n';
    cout << "Length of s35: " << s35->length() << '\n';
    cout << "String of s35: " << s35->toString() << '\n';
    cout << "PreOrder of s35: " << s35->toStringPreOrder() << '\n';
    cout << "Size of Parent s35: " << s35->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s35: " << s35->getParTreeStringPreOrder("") << '\n';
    delete s35;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s20 ====================" << '\n';
    cout << "Length of s20: " << s20->length() << '\n';
    cout << "String of s20: " << s20->toString() << '\n';
    cout << "PreOrder of s20: " << s20->toStringPreOrder() << '\n';
    cout << "Size of Parent s20: " << s20->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s20: " << s20->getParTreeStringPreOrder("") << '\n';
    delete s20;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s0 ====================" << '\n';
    cout << "Length of s0: " << s0->length() << '\n';
    cout << "String of s0: " << s0->toString() << '\n';
    cout << "PreOrder of s0: " << s0->toStringPreOrder() << '\n';
    cout << "Size of Parent s0: " << s0->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s0: " << s0->getParTreeStringPreOrder("") << '\n';
    delete s0;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s14 ====================" << '\n';
    cout << "Length of s14: " << s14->length() << '\n';
    cout << "String of s14: " << s14->toString() << '\n';
    cout << "PreOrder of s14: " << s14->toStringPreOrder() << '\n';
    cout << "Size of Parent s14: " << s14->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s14: " << s14->getParTreeStringPreOrder("") << '\n';
    delete s14;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s15 ====================" << '\n';
    cout << "Length of s15: " << s15->length() << '\n';
    cout << "String of s15: " << s15->toString() << '\n';
    cout << "PreOrder of s15: " << s15->toStringPreOrder() << '\n';
    cout << "Size of Parent s15: " << s15->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s15: " << s15->getParTreeStringPreOrder("") << '\n';
    delete s15;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s16 ====================" << '\n';
    cout << "Length of s16: " << s16->length() << '\n';
    cout << "String of s16: " << s16->toString() << '\n';
    cout << "PreOrder of s16: " << s16->toStringPreOrder() << '\n';
    cout << "Size of Parent s16: " << s16->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s16: " << s16->getParTreeStringPreOrder("") << '\n';
    delete s16;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s31 ====================" << '\n';
    cout << "Length of s31: " << s31->length() << '\n';
    cout << "String of s31: " << s31->toString() << '\n';
    cout << "PreOrder of s31: " << s31->toStringPreOrder() << '\n';
    cout << "Size of Parent s31: " << s31->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s31: " << s31->getParTreeStringPreOrder("") << '\n';
    delete s31;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s19 ====================" << '\n';
    cout << "Length of s19: " << s19->length() << '\n';
    cout << "String of s19: " << s19->toString() << '\n';
    cout << "PreOrder of s19: " << s19->toStringPreOrder() << '\n';
    cout << "Size of Parent s19: " << s19->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s19: " << s19->getParTreeStringPreOrder("") << '\n';
    delete s19;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s6 ====================" << '\n';
    cout << "Length of s6: " << s6->length() << '\n';
    cout << "String of s6: " << s6->toString() << '\n';
    cout << "PreOrder of s6: " << s6->toStringPreOrder() << '\n';
    cout << "Size of Parent s6: " << s6->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s6: " << s6->getParTreeStringPreOrder("") << '\n';
    delete s6;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s22 ====================" << '\n';
    cout << "Length of s22: " << s22->length() << '\n';
    cout << "String of s22: " << s22->toString() << '\n';
    cout << "PreOrder of s22: " << s22->toStringPreOrder() << '\n';
    cout << "Size of Parent s22: " << s22->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s22: " << s22->getParTreeStringPreOrder("") << '\n';
    delete s22;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s1 ====================" << '\n';
    cout << "Length of s1: " << s1->length() << '\n';
    cout << "String of s1: " << s1->toString() << '\n';
    cout << "PreOrder of s1: " << s1->toStringPreOrder() << '\n';
    cout << "Size of Parent s1: " << s1->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s1: " << s1->getParTreeStringPreOrder("") << '\n';
    delete s1;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s25 ====================" << '\n';
    cout << "Length of s25: " << s25->length() << '\n';
    cout << "String of s25: " << s25->toString() << '\n';
    cout << "PreOrder of s25: " << s25->toStringPreOrder() << '\n';
    cout << "Size of Parent s25: " << s25->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s25: " << s25->getParTreeStringPreOrder("") << '\n';
    delete s25;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s26 ====================" << '\n';
    cout << "Length of s26: " << s26->length() << '\n';
    cout << "String of s26: " << s26->toString() << '\n';
    cout << "PreOrder of s26: " << s26->toStringPreOrder() << '\n';
    cout << "Size of Parent s26: " << s26->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s26: " << s26->getParTreeStringPreOrder("") << '\n';
    delete s26;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s27 ====================" << '\n';
    cout << "Length of s27: " << s27->length() << '\n';
    cout << "String of s27: " << s27->toString() << '\n';
    cout << "PreOrder of s27: " << s27->toStringPreOrder() << '\n';
    cout << "Size of Parent s27: " << s27->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s27: " << s27->getParTreeStringPreOrder("") << '\n';
    delete s27;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s10 ====================" << '\n';
    cout << "Length of s10: " << s10->length() << '\n';
    cout << "String of s10: " << s10->toString() << '\n';
    cout << "PreOrder of s10: " << s10->toStringPreOrder() << '\n';
    cout << "Size of Parent s10: " << s10->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s10: " << s10->getParTreeStringPreOrder("") << '\n';
    delete s10;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s28 ====================" << '\n';
    cout << "Length of s28: " << s28->length() << '\n';
    cout << "String of s28: " << s28->toString() << '\n';
    cout << "PreOrder of s28: " << s28->toStringPreOrder() << '\n';
    cout << "Size of Parent s28: " << s28->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s28: " << s28->getParTreeStringPreOrder("") << '\n';
    delete s28;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s30 ====================" << '\n';
    cout << "Length of s30: " << s30->length() << '\n';
    cout << "String of s30: " << s30->toString() << '\n';
    cout << "PreOrder of s30: " << s30->toStringPreOrder() << '\n';
    cout << "Size of Parent s30: " << s30->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s30: " << s30->getParTreeStringPreOrder("") << '\n';
    delete s30;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s23 ====================" << '\n';
    cout << "Length of s23: " << s23->length() << '\n';
    cout << "String of s23: " << s23->toString() << '\n';
    cout << "PreOrder of s23: " << s23->toStringPreOrder() << '\n';
    cout << "Size of Parent s23: " << s23->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s23: " << s23->getParTreeStringPreOrder("") << '\n';
    delete s23;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';

    /*

    */
}

void tc6() {
    ConcatStringTree* s1 = new ConcatStringTree("a");
    ConcatStringTree* s2 = new ConcatStringTree("b");
    ConcatStringTree* s3 = new ConcatStringTree(s1->concat(*s2));

    cout << s3->getParTreeSize("l") << endl;
    cout << s3->getParTreeStringPreOrder("l") << endl;

    delete s1;
    delete s3;
    delete s2;
}

void test1() {
    HashConfig hashConfig(2, 0.5, 0.5, 0.75, 2, 4);
    LitStringHash* litStringHash = new LitStringHash(hashConfig);

    ReducedConcatStringTree* s0 = new ReducedConcatStringTree("0123456789", litStringHash);
    ReducedConcatStringTree* s1 = new ReducedConcatStringTree("0123456789", litStringHash);
    ReducedConcatStringTree* s2 = new ReducedConcatStringTree("0123456789", litStringHash);
    ReducedConcatStringTree* s3 = new ReducedConcatStringTree("0123456789", litStringHash);
    ReducedConcatStringTree* s4 = new ReducedConcatStringTree("0123456789", litStringHash);
    ReducedConcatStringTree* s5 = new ReducedConcatStringTree("0123456789", litStringHash);
    ReducedConcatStringTree* s6 = new ReducedConcatStringTree("0123456789", litStringHash);
    ReducedConcatStringTree* s7 = new ReducedConcatStringTree("0123456789", litStringHash);

    ReducedConcatStringTree* s8 = new ReducedConcatStringTree(s0->concat(*s1));
    ReducedConcatStringTree* s9 = new ReducedConcatStringTree(s1->concat(*s2));
    ReducedConcatStringTree* s10 = new ReducedConcatStringTree(s2->concat(*s3));
    ReducedConcatStringTree* s11 = new ReducedConcatStringTree(s3->concat(*s4));
    ReducedConcatStringTree* s12 = new ReducedConcatStringTree(s4->concat(*s5));
    ReducedConcatStringTree* s13 = new ReducedConcatStringTree(s5->concat(*s6));
    ReducedConcatStringTree* s14 = new ReducedConcatStringTree(s6->concat(*s7));

    ReducedConcatStringTree* s15 = new ReducedConcatStringTree(s8->concat(*s9));
    ReducedConcatStringTree* s16 = new ReducedConcatStringTree(s9->concat(*s10));
    ReducedConcatStringTree* s17 = new ReducedConcatStringTree(s10->concat(*s11));
    ReducedConcatStringTree* s18 = new ReducedConcatStringTree(s11->concat(*s12));
    ReducedConcatStringTree* s19 = new ReducedConcatStringTree(s12->concat(*s13));
    ReducedConcatStringTree* s20 = new ReducedConcatStringTree(s13->concat(*s14));

    ReducedConcatStringTree* s21 = new ReducedConcatStringTree(s15->concat(*s16));
    ReducedConcatStringTree* s22 = new ReducedConcatStringTree(s16->concat(*s17));
    ReducedConcatStringTree* s23 = new ReducedConcatStringTree(s17->concat(*s18));
    ReducedConcatStringTree* s24 = new ReducedConcatStringTree(s18->concat(*s19));
    ReducedConcatStringTree* s25 = new ReducedConcatStringTree(s19->concat(*s20));

    ReducedConcatStringTree* s26 = new ReducedConcatStringTree(s21->concat(*s22));
    ReducedConcatStringTree* s27 = new ReducedConcatStringTree(s22->concat(*s23));
    ReducedConcatStringTree* s28 = new ReducedConcatStringTree(s23->concat(*s24));
    ReducedConcatStringTree* s29 = new ReducedConcatStringTree(s24->concat(*s25));

    ReducedConcatStringTree* s30 = new ReducedConcatStringTree(s26->concat(*s27));
    ReducedConcatStringTree* s31 = new ReducedConcatStringTree(s27->concat(*s28));
    ReducedConcatStringTree* s32 = new ReducedConcatStringTree(s28->concat(*s29));

    ReducedConcatStringTree* s33 = new ReducedConcatStringTree(s30->concat(*s31));
    ReducedConcatStringTree* s34 = new ReducedConcatStringTree(s31->concat(*s32));

    ReducedConcatStringTree* s35 = new ReducedConcatStringTree(s33->concat(*s34));

    cout << "==================== BEFORE DELETE ====================" << '\n';
    cout << "PreOrder of Parent s0: " << s0->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s1: " << s1->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s2: " << s2->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s3: " << s3->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s4: " << s4->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s5: " << s5->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s6: " << s6->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s7: " << s7->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s8: " << s8->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s9: " << s9->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s10: " << s10->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s11: " << s11->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s12: " << s12->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s13: " << s13->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s14: " << s14->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s15: " << s15->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s16: " << s16->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s17: " << s17->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s18: " << s18->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s19: " << s19->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s20: " << s20->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s21: " << s21->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s22: " << s22->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s23: " << s23->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s24: " << s24->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s25: " << s25->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s26: " << s26->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s27: " << s27->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s28: " << s28->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s29: " << s29->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s30: " << s30->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s31: " << s31->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s32: " << s32->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s33: " << s33->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s34: " << s34->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s35: " << s35->getParTreeStringPreOrder("") << '\n';
    cout << "==================== END ====================" << '\n';

    delete s4;
    delete s5;
    delete s7;
    delete s9;
    delete s13;
    delete s17;
    delete s18;
    delete s21;
    delete s24;
    delete s33;
    delete s34;

    cout << "==================== CALLING s29 ====================" << '\n';
    cout << "Length of s29: " << s29->length() << '\n';
    cout << "String of s29: " << s29->toString() << '\n';
    cout << "PreOrder of s29: " << s29->toStringPreOrder() << '\n';
    cout << "Size of Parent s29: " << s29->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s29: " << s29->getParTreeStringPreOrder("") << '\n';
    delete s29;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s32 ====================" << '\n';
    cout << "Length of s32: " << s32->length() << '\n';
    cout << "String of s32: " << s32->toString() << '\n';
    cout << "PreOrder of s32: " << s32->toStringPreOrder() << '\n';
    cout << "Size of Parent s32: " << s32->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s32: " << s32->getParTreeStringPreOrder("") << '\n';
    delete s32;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s3 ====================" << '\n';
    cout << "Length of s3: " << s3->length() << '\n';
    cout << "String of s3: " << s3->toString() << '\n';
    cout << "PreOrder of s3: " << s3->toStringPreOrder() << '\n';
    cout << "Size of Parent s3: " << s3->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s3: " << s3->getParTreeStringPreOrder("") << '\n';
    delete s3;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s8 ====================" << '\n';
    cout << "Length of s8: " << s8->length() << '\n';
    cout << "String of s8: " << s8->toString() << '\n';
    cout << "PreOrder of s8: " << s8->toStringPreOrder() << '\n';
    cout << "Size of Parent s8: " << s8->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s8: " << s8->getParTreeStringPreOrder("") << '\n';
    delete s8;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s2 ====================" << '\n';
    cout << "Length of s2: " << s2->length() << '\n';
    cout << "String of s2: " << s2->toString() << '\n';
    cout << "PreOrder of s2: " << s2->toStringPreOrder() << '\n';
    cout << "Size of Parent s2: " << s2->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s2: " << s2->getParTreeStringPreOrder("") << '\n';
    delete s2;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s11 ====================" << '\n';
    cout << "Length of s11: " << s11->length() << '\n';
    cout << "String of s11: " << s11->toString() << '\n';
    cout << "PreOrder of s11: " << s11->toStringPreOrder() << '\n';
    cout << "Size of Parent s11: " << s11->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s11: " << s11->getParTreeStringPreOrder("") << '\n';
    delete s11;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s12 ====================" << '\n';
    cout << "Length of s12: " << s12->length() << '\n';
    cout << "String of s12: " << s12->toString() << '\n';
    cout << "PreOrder of s12: " << s12->toStringPreOrder() << '\n';
    cout << "Size of Parent s12: " << s12->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s12: " << s12->getParTreeStringPreOrder("") << '\n';
    delete s12;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s35 ====================" << '\n';
    cout << "Length of s35: " << s35->length() << '\n';
    cout << "String of s35: " << s35->toString() << '\n';
    cout << "PreOrder of s35: " << s35->toStringPreOrder() << '\n';
    cout << "Size of Parent s35: " << s35->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s35: " << s35->getParTreeStringPreOrder("") << '\n';
    delete s35;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s20 ====================" << '\n';
    cout << "Length of s20: " << s20->length() << '\n';
    cout << "String of s20: " << s20->toString() << '\n';
    cout << "PreOrder of s20: " << s20->toStringPreOrder() << '\n';
    cout << "Size of Parent s20: " << s20->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s20: " << s20->getParTreeStringPreOrder("") << '\n';
    delete s20;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s0 ====================" << '\n';
    cout << "Length of s0: " << s0->length() << '\n';
    cout << "String of s0: " << s0->toString() << '\n';
    cout << "PreOrder of s0: " << s0->toStringPreOrder() << '\n';
    cout << "Size of Parent s0: " << s0->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s0: " << s0->getParTreeStringPreOrder("") << '\n';
    delete s0;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s14 ====================" << '\n';
    cout << "Length of s14: " << s14->length() << '\n';
    cout << "String of s14: " << s14->toString() << '\n';
    cout << "PreOrder of s14: " << s14->toStringPreOrder() << '\n';
    cout << "Size of Parent s14: " << s14->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s14: " << s14->getParTreeStringPreOrder("") << '\n';
    delete s14;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s15 ====================" << '\n';
    cout << "Length of s15: " << s15->length() << '\n';
    cout << "String of s15: " << s15->toString() << '\n';
    cout << "PreOrder of s15: " << s15->toStringPreOrder() << '\n';
    cout << "Size of Parent s15: " << s15->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s15: " << s15->getParTreeStringPreOrder("") << '\n';
    delete s15;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s16 ====================" << '\n';
    cout << "Length of s16: " << s16->length() << '\n';
    cout << "String of s16: " << s16->toString() << '\n';
    cout << "PreOrder of s16: " << s16->toStringPreOrder() << '\n';
    cout << "Size of Parent s16: " << s16->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s16: " << s16->getParTreeStringPreOrder("") << '\n';
    delete s16;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s31 ====================" << '\n';
    cout << "Length of s31: " << s31->length() << '\n';
    cout << "String of s31: " << s31->toString() << '\n';
    cout << "PreOrder of s31: " << s31->toStringPreOrder() << '\n';
    cout << "Size of Parent s31: " << s31->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s31: " << s31->getParTreeStringPreOrder("") << '\n';
    delete s31;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s19 ====================" << '\n';
    cout << "Length of s19: " << s19->length() << '\n';
    cout << "String of s19: " << s19->toString() << '\n';
    cout << "PreOrder of s19: " << s19->toStringPreOrder() << '\n';
    cout << "Size of Parent s19: " << s19->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s19: " << s19->getParTreeStringPreOrder("") << '\n';
    delete s19;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s6 ====================" << '\n';
    cout << "Length of s6: " << s6->length() << '\n';
    cout << "String of s6: " << s6->toString() << '\n';
    cout << "PreOrder of s6: " << s6->toStringPreOrder() << '\n';
    cout << "Size of Parent s6: " << s6->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s6: " << s6->getParTreeStringPreOrder("") << '\n';
    delete s6;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s22 ====================" << '\n';
    cout << "Length of s22: " << s22->length() << '\n';
    cout << "String of s22: " << s22->toString() << '\n';
    cout << "PreOrder of s22: " << s22->toStringPreOrder() << '\n';
    cout << "Size of Parent s22: " << s22->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s22: " << s22->getParTreeStringPreOrder("") << '\n';
    delete s22;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s1 ====================" << '\n';
    cout << "Length of s1: " << s1->length() << '\n';
    cout << "String of s1: " << s1->toString() << '\n';
    cout << "PreOrder of s1: " << s1->toStringPreOrder() << '\n';
    cout << "Size of Parent s1: " << s1->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s1: " << s1->getParTreeStringPreOrder("") << '\n';
    delete s1;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s25 ====================" << '\n';
    cout << "Length of s25: " << s25->length() << '\n';
    cout << "String of s25: " << s25->toString() << '\n';
    cout << "PreOrder of s25: " << s25->toStringPreOrder() << '\n';
    cout << "Size of Parent s25: " << s25->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s25: " << s25->getParTreeStringPreOrder("") << '\n';
    delete s25;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s26 ====================" << '\n';
    cout << "Length of s26: " << s26->length() << '\n';
    cout << "String of s26: " << s26->toString() << '\n';
    cout << "PreOrder of s26: " << s26->toStringPreOrder() << '\n';
    cout << "Size of Parent s26: " << s26->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s26: " << s26->getParTreeStringPreOrder("") << '\n';
    delete s26;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s27 ====================" << '\n';
    cout << "Length of s27: " << s27->length() << '\n';
    cout << "String of s27: " << s27->toString() << '\n';
    cout << "PreOrder of s27: " << s27->toStringPreOrder() << '\n';
    cout << "Size of Parent s27: " << s27->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s27: " << s27->getParTreeStringPreOrder("") << '\n';
    delete s27;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s10 ====================" << '\n';
    cout << "Length of s10: " << s10->length() << '\n';
    cout << "String of s10: " << s10->toString() << '\n';
    cout << "PreOrder of s10: " << s10->toStringPreOrder() << '\n';
    cout << "Size of Parent s10: " << s10->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s10: " << s10->getParTreeStringPreOrder("") << '\n';
    delete s10;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s28 ====================" << '\n';
    cout << "Length of s28: " << s28->length() << '\n';
    cout << "String of s28: " << s28->toString() << '\n';
    cout << "PreOrder of s28: " << s28->toStringPreOrder() << '\n';
    cout << "Size of Parent s28: " << s28->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s28: " << s28->getParTreeStringPreOrder("") << '\n';
    delete s28;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s30 ====================" << '\n';
    cout << "Length of s30: " << s30->length() << '\n';
    cout << "String of s30: " << s30->toString() << '\n';
    cout << "PreOrder of s30: " << s30->toStringPreOrder() << '\n';
    cout << "Size of Parent s30: " << s30->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s30: " << s30->getParTreeStringPreOrder("") << '\n';
    delete s30;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s23 ====================" << '\n';
    cout << "Length of s23: " << s23->length() << '\n';
    cout << "String of s23: " << s23->toString() << '\n';
    cout << "PreOrder of s23: " << s23->toStringPreOrder() << '\n';
    cout << "Size of Parent s23: " << s23->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s23: " << s23->getParTreeStringPreOrder("") << '\n';
    delete s23;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';

    delete litStringHash;
}


void tc7() {
    ConcatStringTree* s0 = new ConcatStringTree("0123456789");
    ConcatStringTree* s1 = new ConcatStringTree("0123456789");
    ConcatStringTree* s2 = new ConcatStringTree("0123456789");
    ConcatStringTree* s3 = new ConcatStringTree("0123456789");
    ConcatStringTree* s4 = new ConcatStringTree("0123456789");
    ConcatStringTree* s5 = new ConcatStringTree("0123456789");
    ConcatStringTree* s6 = new ConcatStringTree("0123456789");
    ConcatStringTree* s7 = new ConcatStringTree("0123456789");
    ConcatStringTree* s8 = new ConcatStringTree("0123456789");
    ConcatStringTree* s9 = new ConcatStringTree("0123456789");
    ConcatStringTree* s10 = new ConcatStringTree("0123456789");
    ConcatStringTree* s11 = new ConcatStringTree("0123456789");
    ConcatStringTree* s12 = new ConcatStringTree("0123456789");
    ConcatStringTree* s13 = new ConcatStringTree("0123456789");
    ConcatStringTree* s14 = new ConcatStringTree("0123456789");
    ConcatStringTree* s15 = new ConcatStringTree("0123456789");
    ConcatStringTree* s16 = new ConcatStringTree("0123456789");
    ConcatStringTree* s17 = new ConcatStringTree("0123456789");
    ConcatStringTree* s18 = new ConcatStringTree("0123456789");
    ConcatStringTree* s19 = new ConcatStringTree("0123456789");
    ConcatStringTree* s20 = new ConcatStringTree("0123456789");
    ConcatStringTree* s21 = new ConcatStringTree("0123456789");
    ConcatStringTree* s22 = new ConcatStringTree("0123456789");
    ConcatStringTree* s23 = new ConcatStringTree("0123456789");

    ConcatStringTree* s24 = new ConcatStringTree(s0->concat(*s1));
    ConcatStringTree* s25 = new ConcatStringTree(s0->concat(*s2));
    ConcatStringTree* s26 = new ConcatStringTree(s0->concat(*s3));
    ConcatStringTree* s27 = new ConcatStringTree(s0->concat(*s4));
    ConcatStringTree* s28 = new ConcatStringTree(s0->concat(*s5));
    ConcatStringTree* s29 = new ConcatStringTree(s0->concat(*s6));
    ConcatStringTree* s30 = new ConcatStringTree(s0->concat(*s7));
    ConcatStringTree* s45 = new ConcatStringTree(s0->concat(*s8));
    ConcatStringTree* s31 = new ConcatStringTree(s0->concat(*s9));
    ConcatStringTree* s32 = new ConcatStringTree(s0->concat(*s10));
    ConcatStringTree* s33 = new ConcatStringTree(s0->concat(*s11));
    ConcatStringTree* s34 = new ConcatStringTree(s0->concat(*s12));
    ConcatStringTree* s35 = new ConcatStringTree(s0->concat(*s13));
    ConcatStringTree* s36 = new ConcatStringTree(s0->concat(*s14));
    ConcatStringTree* s44 = new ConcatStringTree(s0->concat(*s15));
    ConcatStringTree* s37 = new ConcatStringTree(s0->concat(*s16));
    ConcatStringTree* s38 = new ConcatStringTree(s0->concat(*s17));
    ConcatStringTree* s39 = new ConcatStringTree(s0->concat(*s18));
    ConcatStringTree* s40 = new ConcatStringTree(s0->concat(*s19));
    ConcatStringTree* s41 = new ConcatStringTree(s0->concat(*s20));
    ConcatStringTree* s42 = new ConcatStringTree(s0->concat(*s21));
    ConcatStringTree* s46 = new ConcatStringTree(s0->concat(*s22));
    ConcatStringTree* s43 = new ConcatStringTree(s0->concat(*s23));
    cout << "PreOrder of Parent s0: " << s0->getParTreeStringPreOrder("") << '\n';

    cout << "==================== CALLING s4 ====================" << '\n';
    cout << "Length of s29: " << s4->length() << '\n';
    cout << "String of s29: " << s4->toString() << '\n';
    cout << "PreOrder of s29: " << s4->toStringPreOrder() << '\n';
    cout << "Size of Parent s29: " << s4->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s29: " << s4->getParTreeStringPreOrder("") << '\n';
    delete s4;
    delete s5;
    delete s7;
    delete s9;
    delete s13;
    delete s17;
    delete s18;
    delete s21;
    delete s24;
    delete s33;
    delete s34;
    delete s36;
    delete s37;
    delete s38;
    delete s39;
    delete s40;
    delete s41;
    delete s42;
    delete s43;
    delete s44;
    delete s46;
    delete s45;

    cout << "==================== CALLING s29 ====================" << '\n';
    cout << "Length of s29: " << s29->length() << '\n';
    cout << "String of s29: " << s29->toString() << '\n';
    cout << "PreOrder of s29: " << s29->toStringPreOrder() << '\n';
    cout << "Size of Parent s29: " << s29->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s29: " << s29->getParTreeStringPreOrder("") << '\n';
    delete s29;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s32 ====================" << '\n';
    cout << "Length of s32: " << s32->length() << '\n';
    cout << "String of s32: " << s32->toString() << '\n';
    cout << "PreOrder of s32: " << s32->toStringPreOrder() << '\n';
    cout << "Size of Parent s32: " << s32->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s32: " << s32->getParTreeStringPreOrder("") << '\n';
    delete s32;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s3 ====================" << '\n';
    cout << "Length of s3: " << s3->length() << '\n';
    cout << "String of s3: " << s3->toString() << '\n';
    cout << "PreOrder of s3: " << s3->toStringPreOrder() << '\n';
    cout << "Size of Parent s3: " << s3->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s3: " << s3->getParTreeStringPreOrder("") << '\n';
    delete s3;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s8 ====================" << '\n';
    cout << "Length of s8: " << s8->length() << '\n';
    cout << "String of s8: " << s8->toString() << '\n';
    cout << "PreOrder of s8: " << s8->toStringPreOrder() << '\n';
    cout << "Size of Parent s8: " << s8->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s8: " << s8->getParTreeStringPreOrder("") << '\n';
    delete s8;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s2 ====================" << '\n';
    cout << "Length of s2: " << s2->length() << '\n';
    cout << "String of s2: " << s2->toString() << '\n';
    cout << "PreOrder of s2: " << s2->toStringPreOrder() << '\n';
    cout << "Size of Parent s2: " << s2->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s2: " << s2->getParTreeStringPreOrder("") << '\n';
    delete s2;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s11 ====================" << '\n';
    cout << "Length of s11: " << s11->length() << '\n';
    cout << "String of s11: " << s11->toString() << '\n';
    cout << "PreOrder of s11: " << s11->toStringPreOrder() << '\n';
    cout << "Size of Parent s11: " << s11->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s11: " << s11->getParTreeStringPreOrder("") << '\n';
    delete s11;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s12 ====================" << '\n';
    cout << "Length of s12: " << s12->length() << '\n';
    cout << "String of s12: " << s12->toString() << '\n';
    cout << "PreOrder of s12: " << s12->toStringPreOrder() << '\n';
    cout << "Size of Parent s12: " << s12->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s12: " << s12->getParTreeStringPreOrder("") << '\n';
    delete s12;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s35 ====================" << '\n';
    cout << "Length of s35: " << s35->length() << '\n';
    cout << "String of s35: " << s35->toString() << '\n';
    cout << "PreOrder of s35: " << s35->toStringPreOrder() << '\n';
    cout << "Size of Parent s35: " << s35->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s35: " << s35->getParTreeStringPreOrder("") << '\n';
    delete s35;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s20 ====================" << '\n';
    cout << "Length of s20: " << s20->length() << '\n';
    cout << "String of s20: " << s20->toString() << '\n';
    cout << "PreOrder of s20: " << s20->toStringPreOrder() << '\n';
    cout << "Size of Parent s20: " << s20->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s20: " << s20->getParTreeStringPreOrder("") << '\n';
    delete s20;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s0 ====================" << '\n';
    cout << "Length of s0: " << s0->length() << '\n';
    cout << "String of s0: " << s0->toString() << '\n';
    cout << "PreOrder of s0: " << s0->toStringPreOrder() << '\n';
    cout << "Size of Parent s0: " << s0->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s0: " << s0->getParTreeStringPreOrder("") << '\n';
    delete s0;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s14 ====================" << '\n';
    cout << "Length of s14: " << s14->length() << '\n';
    cout << "String of s14: " << s14->toString() << '\n';
    cout << "PreOrder of s14: " << s14->toStringPreOrder() << '\n';
    cout << "Size of Parent s14: " << s14->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s14: " << s14->getParTreeStringPreOrder("") << '\n';
    delete s14;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s15 ====================" << '\n';
    cout << "Length of s15: " << s15->length() << '\n';
    cout << "String of s15: " << s15->toString() << '\n';
    cout << "PreOrder of s15: " << s15->toStringPreOrder() << '\n';
    cout << "Size of Parent s15: " << s15->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s15: " << s15->getParTreeStringPreOrder("") << '\n';
    delete s15;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s16 ====================" << '\n';
    cout << "Length of s16: " << s16->length() << '\n';
    cout << "String of s16: " << s16->toString() << '\n';
    cout << "PreOrder of s16: " << s16->toStringPreOrder() << '\n';
    cout << "Size of Parent s16: " << s16->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s16: " << s16->getParTreeStringPreOrder("") << '\n';
    delete s16;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s31 ====================" << '\n';
    cout << "Length of s31: " << s31->length() << '\n';
    cout << "String of s31: " << s31->toString() << '\n';
    cout << "PreOrder of s31: " << s31->toStringPreOrder() << '\n';
    cout << "Size of Parent s31: " << s31->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s31: " << s31->getParTreeStringPreOrder("") << '\n';
    delete s31;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s19 ====================" << '\n';
    cout << "Length of s19: " << s19->length() << '\n';
    cout << "String of s19: " << s19->toString() << '\n';
    cout << "PreOrder of s19: " << s19->toStringPreOrder() << '\n';
    cout << "Size of Parent s19: " << s19->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s19: " << s19->getParTreeStringPreOrder("") << '\n';
    delete s19;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s6 ====================" << '\n';
    cout << "Length of s6: " << s6->length() << '\n';
    cout << "String of s6: " << s6->toString() << '\n';
    cout << "PreOrder of s6: " << s6->toStringPreOrder() << '\n';
    cout << "Size of Parent s6: " << s6->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s6: " << s6->getParTreeStringPreOrder("") << '\n';
    delete s6;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s22 ====================" << '\n';
    cout << "Length of s22: " << s22->length() << '\n';
    cout << "String of s22: " << s22->toString() << '\n';
    cout << "PreOrder of s22: " << s22->toStringPreOrder() << '\n';
    cout << "Size of Parent s22: " << s22->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s22: " << s22->getParTreeStringPreOrder("") << '\n';
    delete s22;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s1 ====================" << '\n';
    cout << "Length of s1: " << s1->length() << '\n';
    cout << "String of s1: " << s1->toString() << '\n';
    cout << "PreOrder of s1: " << s1->toStringPreOrder() << '\n';
    cout << "Size of Parent s1: " << s1->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s1: " << s1->getParTreeStringPreOrder("") << '\n';
    delete s1;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s25 ====================" << '\n';
    cout << "Length of s25: " << s25->length() << '\n';
    cout << "String of s25: " << s25->toString() << '\n';
    cout << "PreOrder of s25: " << s25->toStringPreOrder() << '\n';
    cout << "Size of Parent s25: " << s25->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s25: " << s25->getParTreeStringPreOrder("") << '\n';
    delete s25;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s26 ====================" << '\n';
    cout << "Length of s26: " << s26->length() << '\n';
    cout << "String of s26: " << s26->toString() << '\n';
    cout << "PreOrder of s26: " << s26->toStringPreOrder() << '\n';
    cout << "Size of Parent s26: " << s26->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s26: " << s26->getParTreeStringPreOrder("") << '\n';
    delete s26;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s27 ====================" << '\n';
    cout << "Length of s27: " << s27->length() << '\n';
    cout << "String of s27: " << s27->toString() << '\n';
    cout << "PreOrder of s27: " << s27->toStringPreOrder() << '\n';
    cout << "Size of Parent s27: " << s27->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s27: " << s27->getParTreeStringPreOrder("") << '\n';
    delete s27;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s10 ====================" << '\n';
    cout << "Length of s10: " << s10->length() << '\n';
    cout << "String of s10: " << s10->toString() << '\n';
    cout << "PreOrder of s10: " << s10->toStringPreOrder() << '\n';
    cout << "Size of Parent s10: " << s10->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s10: " << s10->getParTreeStringPreOrder("") << '\n';
    delete s10;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s28 ====================" << '\n';
    cout << "Length of s28: " << s28->length() << '\n';
    cout << "String of s28: " << s28->toString() << '\n';
    cout << "PreOrder of s28: " << s28->toStringPreOrder() << '\n';
    cout << "Size of Parent s28: " << s28->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s28: " << s28->getParTreeStringPreOrder("") << '\n';
    delete s28;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s30 ====================" << '\n';
    cout << "Length of s30: " << s30->length() << '\n';
    cout << "String of s30: " << s30->toString() << '\n';
    cout << "PreOrder of s30: " << s30->toStringPreOrder() << '\n';
    cout << "Size of Parent s30: " << s30->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s30: " << s30->getParTreeStringPreOrder("") << '\n';
    delete s30;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';
    cout << "==================== CALLING s23 ====================" << '\n';
    cout << "Length of s23: " << s23->length() << '\n';
    cout << "String of s23: " << s23->toString() << '\n';
    cout << "PreOrder of s23: " << s23->toStringPreOrder() << '\n';
    cout << "Size of Parent s23: " << s23->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s23: " << s23->getParTreeStringPreOrder("") << '\n';
    delete s23;
    cout << "==================== END CALLING ====================" << '\n';
    cout << '\n';

}

void tc8() {
    HashConfig hashConfig(2, 0.5, 0.5, 0.75, 2, 4);
    LitStringHash* litStringHash = new LitStringHash(hashConfig);

    ReducedConcatStringTree* s1 = new ReducedConcatStringTree("a", litStringHash);
    ReducedConcatStringTree* s2 = new ReducedConcatStringTree("a", litStringHash);
    ReducedConcatStringTree* s3 = new ReducedConcatStringTree(s1->concat(*s2));
    ReducedConcatStringTree* s4 = new ReducedConcatStringTree("a", litStringHash);
    ReducedConcatStringTree* s5 = new ReducedConcatStringTree("a", litStringHash);
    ReducedConcatStringTree* s6 = new ReducedConcatStringTree(s4->concat(*s5));
    ReducedConcatStringTree* s7 = new ReducedConcatStringTree(s3->concat(*s6));
    ReducedConcatStringTree* s8 = new ReducedConcatStringTree(s1->concat(*s4));

    cout << s1->getParTreeSize("") << endl;
    cout << s1->getParTreeStringPreOrder("") << endl;

    delete s3;
    delete s2;
    delete s1;
    delete s6;
    delete s5;
    delete s4;
    delete s7;
    delete s8;
    delete litStringHash;
}

void tc9() {
    ConcatStringTree s1("Hello");
    ConcatStringTree s2(",_t");
    ConcatStringTree s3 = s1.concat(s2);
    ConcatStringTree s4("his_is_a");
    ConcatStringTree s5("ssignment_");
    ConcatStringTree s6 = s4.concat(s5);
    ConcatStringTree s7 = s3.concat(s6);
    cout << s7.toStringPreOrder() << endl;
    cout << s7.toString() << endl;
    cout << s7.subString(0, 20).toStringPreOrder() << endl;
    cout << s7.subString(0, 20).toString() << endl;
    cout << s7.reverse().toStringPreOrder() << endl;
    cout << s7.reverse().toString() << endl;
}

void tc10() {
    HashConfig hashConfig(2, 0.5, 0.5, 0.75, 2, 4);
    LitStringHash* litStringHash = new LitStringHash(hashConfig);
    ReducedConcatStringTree* s1 = new ReducedConcatStringTree("abc", litStringHash);
    ReducedConcatStringTree* s2 = new ReducedConcatStringTree("def", litStringHash);
    ReducedConcatStringTree* s3 = new ReducedConcatStringTree("def", litStringHash);
    ReducedConcatStringTree* s4 = new ReducedConcatStringTree(s1->concat(*s2));
    ReducedConcatStringTree* s5 = new ReducedConcatStringTree(s2->concat(*s3));
    cout << "==================== BEFORE DELETE ====================" << '\n';
    cout << "PreOrder of Parent s1: " << s1->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s2: " << s2->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s3: " << s3->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s4: " << s4->getParTreeStringPreOrder("") << '\n';
    cout << "PreOrder of Parent s5: " << s5->getParTreeStringPreOrder("") << '\n';
    cout << "==================== END ====================" << '\n';

    cout << "==================== CALLING s1 ====================" << '\n';
    cout << "Length of s1: " << s1->length() << '\n';
    cout << "String of s1: " << s1->toString() << '\n';
    cout << "PreOrder of s1: " << s1->toStringPreOrder() << '\n';
    cout << "Size of Parent s1: " << s1->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s1: " << s1->getParTreeStringPreOrder("") << '\n';
    delete s1;
    cout << "==================== END CALLING ====================" << '\n';


    cout << "==================== CALLING s4 ====================" << '\n';
    cout << "Length of s4: " << s4->length() << '\n';
    cout << "String of s4: " << s4->toString() << '\n';
    cout << "PreOrder of s4: " << s4->toStringPreOrder() << '\n';
    cout << "Size of Parent s4: " << s4->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s4: " << s4->getParTreeStringPreOrder("") << '\n';
    delete s4;
    cout << "==================== END CALLING ====================" << '\n';

    cout << "Size of Parent s2: " << s2->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s2: " << s2->getParTreeStringPreOrder("") << '\n';
    delete s2;
    cout << "Size of Parent s3: " << s3->getParTreeSize("") << '\n';
    cout << "PreOrder of Parent s3: " << s3->getParTreeStringPreOrder("") << '\n';
    cout << litStringHash->toString();
    delete s3;
    ///
    delete s5;
    delete litStringHash;
}

void tc351() {

HashConfig hashConfig(
2,
0.5,
0.5,
0.75,
2.0,
4
);
LitStringHash* litStringHash = new LitStringHash(hashConfig);
ReducedConcatStringTree* s1 = new ReducedConcatStringTree("a", litStringHash);
ReducedConcatStringTree* s2 = new ReducedConcatStringTree("b", litStringHash);
ReducedConcatStringTree* s3 = new ReducedConcatStringTree("b", litStringHash);
ReducedConcatStringTree* s4 = new ReducedConcatStringTree("c", litStringHash);

ReducedConcatStringTree* s5 = new ReducedConcatStringTree(s1->concat(*s2));
ReducedConcatStringTree* s6 = new ReducedConcatStringTree(s3->concat(*s4));
ReducedConcatStringTree* s7 = new ReducedConcatStringTree(s5->concat(*s6));
cout << litStringHash->getLastInsertedIndex() << endl;
cout << litStringHash->toString() << endl;

cout << "s7 = " << s7->getParTreeStringPreOrder("") << endl;
cout << "s5 = " << s7->getParTreeStringPreOrder("l") << endl;
cout << "s1 = " << s7->getParTreeStringPreOrder("ll") << endl;
cout << "s2 = " << s7->getParTreeStringPreOrder("lr") << endl;
cout << "s6 = " << s7->getParTreeStringPreOrder("r") << endl;
cout << "s3 = " << s7->getParTreeStringPreOrder("rl") << endl;
cout << "s4 = " << s7->getParTreeStringPreOrder("rr") << endl;

delete s4;
delete s1;
delete s2;
delete s3;
delete s5;
delete s6;
delete s7;
delete litStringHash;
}

int main() {
    
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    test();
    return 0;
}