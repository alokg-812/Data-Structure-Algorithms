void inorder(Node* root){
    Node curr = root;
    Stack<Node> st;
    while(curr!=NULL || st.size()>0){
        while(curr!=NULL){
            st.push(curr);
            curr = curr.left;
        }
        curr = st.top();
        st.pop();
        cout<<curr.data<<" ";
        curr = curr.right;
    }
}
