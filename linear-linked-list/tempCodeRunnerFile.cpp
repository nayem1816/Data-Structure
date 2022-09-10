
    {
        cout << temp->value;
        temp = temp->next;
        if (temp != head)
        {
            cout << " -> ";
        }
    } while (temp != head);
    cout << endl;