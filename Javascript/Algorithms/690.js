/**
 * Definition for Employee.
 * function Employee(id, importance, subordinates) {
 *     this.id = id;
 *     this.importance = importance;
 *     this.subordinates = subordinates;
 * }
 */

let GetImportance = (employees, id) => {
    const empls = new Map;
    for (let e of employees){
        empls.set(e.id, [e.importance, e.subordinates]);
    }
    
    let [importance, subords] = empls.get(id);
    while (subords.length){
        let subord_id = subords.pop();
        let [s_imp, s_subords] = empls.get(subord_id);
        
        importance += s_imp;
        if (s_subords.length){
            subords.push(...s_subords);
        }
    }
    return importance;
};
