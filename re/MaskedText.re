[@bs.module "react-native-masked-text"] external textInputMasked : ReasonReact.reactClass =
  "textInputMasked";

type maskType = [
  | `creditCard
  | `zipcode
  | `datetime
  | `custom
  | `onlyNumbers
  | `celPhone
  | `money
  | `cnpj
  | `cpf
];

let make =
    (
      ~placeholder: string,
      ~maskType: maskType,
      ~style=?,
      ~value: option(string),
      ~onChangeText: string => unit,
      children
    ) => {
  let mask =
    switch maskType {
    | `custom => "custom"
    | `creditCard => "credit-card"
    | `zipcode => "zipcode"
    | `datetime => "datetime"
    | `onlyNumbers => "only-numbers"
    | `celPhone => "celphone"
    | `money => "money"
    | `cnpj => "cnpj"
    | `cpf => "cpf"
    };
  ReasonReact.wrapJsForReason(
    ~reactClass=textInputMasked,
    ~props={
      "style": style,
      "type": mask,
      "onChangeText": onChangeText,
      "value": value,
      "placeholder": placeholder
    },
    children
  )
};
